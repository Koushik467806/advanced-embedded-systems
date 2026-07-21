# UART

- Asynchronous serial communication
- Can adjust data transmission speeds

---

## Interface

- Connect **TX** of device 1 to **RX** of device 2, and vice versa
- Connect **GND** to **GND**

---

## How It Works

- Line is initially held **high** (idle state)
- A **start bit** (`0`) begins every message, indicating the start of a data transfer
- Data is transferred **bit by bit** (5 to 9 bits)
- An optional **parity bit** is sent for error checking
- A **stop bit** signals the end of the data packet (line is driven high again)

### Frame Structure

| Field | Value | Description |
|-------|-------|-------------|
| Start bit | `0` | Marks the start of a data frame |
| Data bits | 5–9 bits | The actual data being transmitted |
| Parity bit | Optional | Used for error checking |
| Stop bit | `1` | Signals the end of the data frame; line returns to high |

### Parity Bit

| Type | Value |
|------|-------|
| Even parity | `0` if the number of `1`s in the data is even, otherwise `1` |
| Odd parity | `0` if the number of `1`s in the data is odd, otherwise `1` |

---

## Baud Rate

- The speed at which data is transmitted, measured in **bits per second (bps)**
- **Baud rate** refers to the number of signal changes per second
- **Bit rate** refers to the number of bits transmitted per second
- In simple systems, each signal change represents one bit → baud rate equals bit rate
- In more complex systems, each signal change can represent multiple bits → bit rate is higher than baud rate

### Formula

- **Baud Rate equation:**
  ```text
  Baud Rate = f_CK / (16 * USARTDIV)
  ```

- **USARTDIV (Register Divider) equation:**
  ```text
  USARTDIV = f_CK / (16 * Baud Rate)
  ```

Where:
- `f_CK`: Peripheral clock frequency (in Hz)
- `USARTDIV`: Fixed-point divisor loaded into `USART_BRR`

### Standard Baud Rates

| Baud Rate | Use Case |
|-----------|----------|
| 300 bps | Very slow; used for long-distance communication |
| 9600 bps | Widely used default for many devices |
| 19200 bps | Faster; used in data-intensive applications |
| 115200 bps | High speed; used in applications requiring fast data transfer |

---

## Registers

### 1. USART_SR (Status Register)

| Bit | Name | Description |
|-----|------|-------------|
| TXE | Transmit Data Register Empty | Set when the data register is empty and ready for new data |
| RXNE | Read Data Register Not Empty | Set when the data register contains received data |
| TC | Transmission Complete | Set when the last transmission has completed |
| ORE | Overrun Error | Set when data was lost because the data register was not read before new data arrived |
| PE | Parity Error | Set when a parity error is detected |

```c
// Wait until TX register is empty, then send a byte
while (!(USART2->SR & (1 << 7)));  // wait for TXE
USART2->DR = 'A';

// Wait until data is received
while (!(USART2->SR & (1 << 5)));  // wait for RXNE
char received = USART2->DR;

// Check for overrun error
if (USART2->SR & (1 << 3)) {       // ORE set?
    // handle overrun error
}
```

---

### 2. USART_DR (Data Register)

- Interface for data exchange
- **Transmitting:** writing to `USART_DR` sends data through TX
- **Receiving:** reading from `USART_DR` retrieves the data received on RX

```c
// Transmit a byte
USART2->DR = 0x41;           // send 'A'

// Receive a byte
uint8_t data = USART2->DR;   // read received byte
```

---

### 3. USART_BRR (Baud Rate Register)

- Used to set the baud rate
- Has two fields: **Mantissa** and **Fraction**

```c
// Set baud rate to 9600 with a 16 MHz clock
// USARTDIV = f_CK / (16 * BaudRate) = 16,000,000 / (16 * 9600) = 104.1875
// Mantissa = 104 (0x68), Fraction = 0.1875 * 16 = 3 (0x3)
// BRR = (104 << 4) | 3 = 0x683

USART2->BRR = 0x0683;
```

---

### 4. USART_CR1 (Control Register 1)

- Enables and configures UART functionality

| Bit | Name | Description |
|-----|------|-------------|
| UE | UART Enable | Enables/disables the UART peripheral |
| M | Word Length | Configures word length (`0` = 8-bit, `1` = 9-bit) |
| PCE | Parity Control Enable | Enables parity checking |
| PS | Parity Selection | Selects even (`0`) or odd (`1`) parity |
| TE | Transmitter Enable | Enables the transmitter |
| RE | Receiver Enable | Enables the receiver |

```c
// Configure USART2: 8-bit, no parity, enable TX and RX, then enable UART
USART2->CR1  = 0;             // reset register
USART2->CR1 |= (1 << 3);     // TE  - enable transmitter
USART2->CR1 |= (1 << 2);     // RE  - enable receiver
USART2->CR1 |= (1 << 13);    // UE  - enable UART peripheral
// M bit (bit 12) left as 0   → 8-bit word length
// PCE bit (bit 10) left as 0 → no parity
```
