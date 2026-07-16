# SPI

- Synchronous serial communication
- Short-distance communication (< 30 cm)

---

## Features

- Full-duplex / Half-duplex
- High speed
- Master-slave architecture

---

## Interface

- Uses 4 primary lines:

| Line | Full Name | Description |
|------|-----------|-------------|
| MISO | Master In Slave Out | Carries data from slave to master |
| MOSI | Master Out Slave In | Carries data from master to slave |
| SCK | Serial Clock | Used for synchronization |
| SS | Slave Select | Used by master to select which slave to communicate with |

- If there are multiple slaves, each slave has its own dedicated SS line

---

## How It Works

1. **Initialization** — Master sets clock frequency and data format
2. **Slave selection** — Master pulls the target slave's SS line low
3. **Data transmission** — Master sends data through MOSI; slave sends data through MISO simultaneously
4. **Clock synchronization** — Master controls the clock, ensuring data is sampled at the correct times
5. **Completion** — Master pulls the SS line high when data transmission is complete

> **Note:** Never pull more than one slave's SS line low while receiving data through MISO.
> All SS lines may be pulled low simultaneously only if the master is sending the same data to all slaves and not receiving any data.

---

## CPHA and CPOL

### CPOL — Clock Polarity (determines the idle state of the clock signal)

| Value | Behavior |
|-------|----------|
| `0` | Clock is low when idle |
| `1` | Clock is high when idle |

### CPHA — Clock Phase (determines when data is sampled)

| Value | Behavior |
|-------|----------|
| `0` | Data sampled on the **leading** edge; shifted out on the trailing edge |
| `1` | Data sampled on the **trailing** edge; shifted out on the leading edge |

- **Sampling** — when the bit is read
- **Shifting out** — when the bit is transferred

---

## Data Modes

- Can handle **8-bit**, **16-bit**, and **32-bit** transfers

---

## Registers

### 1. SPI_CR1 (Control Register 1)

| Bit | Name | Description |
|-----|------|-------------|
| 15 | BIDIMODE | `0` = 2-line unidirectional<br>`1` = 1-line bidirectional |
| 10 | RXONLY | `0` = full-duplex (RX and TX)<br>`1` = receive only |
| 9 | SSM | `1` = master controls SS line manually (software slave management) |
| 8 | SSI | Used in master mode to internally control the SS line |
| 7 | LSBFIRST | `0` = MSB first<br>`1` = LSB first |
| 6 | SPE | `0` = peripheral disabled<br>`1` = peripheral enabled |
| 5:3 | BR | Configures the baud rate (clock prescaler) |
| 1 | CPOL | `0` = clock low when idle<br>`1` = clock high when idle |
| 0 | CPHA | `0` = second clock transition is data capture<br>`1` = first transition is data capture |

```c
// Configure SPI1 as master: MSB first, software SS, fPCLK/8, CPOL=0, CPHA=0, enable
SPI1->CR1 = 0;
SPI1->CR1 |= (1 << 9);   // SSM  - software slave management
SPI1->CR1 |= (1 << 8);   // SSI  - internal SS high (master mode)
SPI1->CR1 |= (2 << 3);   // BR   - fPCLK/8 (BR[2:0] = 010)
SPI1->CR1 |= (1 << 2);   // MSTR - master mode
// CPOL = 0, CPHA = 0 (Mode 0) — left as default
SPI1->CR1 |= (1 << 6);   // SPE  - enable SPI peripheral
```

---

### 2. SPI_SR (Status Register)

| Bit | Name | Description |
|-----|------|-------------|
| 0 | RXNE | `0` = RX buffer empty<br>`1` = RX buffer not empty (data available) |
| 1 | TXE | `0` = TX buffer not empty<br>`1` = TX buffer empty (ready for new data) |
| 4 | CRCERR | `0` = no CRC error<br>`1` = CRC error detected |
| 5 | MODF | `0` = no mode fault<br>`1` = mode fault occurred |
| 6 | OVR | `0` = no overrun<br>`1` = overrun occurred |
| 7 | BSY | `0` = SPI not busy<br>`1` = SPI busy (communication in progress) |

```c
// Transmit a byte over SPI
while (!(SPI1->SR & (1 << 1)));   // wait for TXE (TX buffer empty)
SPI1->DR = 0xA5;                  // send data

// Receive a byte over SPI
while (!(SPI1->SR & (1 << 0)));   // wait for RXNE (data available)
uint8_t data = SPI1->DR;          // read received data

// Wait until SPI is not busy before de-asserting SS
while (SPI1->SR & (1 << 7));      // wait for BSY to clear
```

---

### 3. SPI_DR (Data Register)

- Bits [15:0] hold the data received or to be transmitted
- Writing to `SPI_DR` loads data into the TX buffer
- Reading from `SPI_DR` reads data from the RX buffer
