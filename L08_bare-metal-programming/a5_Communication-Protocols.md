# Communication Protocols

- A set of rules that allow devices to communicate with each other

---

## Types of Communication

### By Transmission Method

| Type | Description | Example |
|------|-------------|---------|
| **Serial** | Sends 1 bit at a time | UART, SPI, I2C |
| **Parallel** | Multiple bits sent through multiple channels simultaneously; faster but requires more pins | — |

**Serial communication is further divided into:**

| Mode | Description | Example |
|------|-------------|---------|
| Asynchronous | No clock to synchronize sender and receiver | UART |
| Synchronous | Uses a clock to coordinate the transmission of bits | SPI, I2C |

---

### By Architecture

| Architecture | Description | Example |
|--------------|-------------|---------|
| Point-to-point | Direct line of communication between two devices | UART |
| Multi-master | Multiple devices can control communication | I2C |
| Master-slave | One master controls the communication | SPI, I2C |

---

### By Data Flow

| Mode | Description | Example |
|------|-------------|---------|
| Full-duplex | Simultaneous two-way communication | UART, SPI |
| Half-duplex | Communication can occur from both sides, but not at the same time | I2C |

---

## Protocol Comparison

| Feature | UART | SPI | I2C |
|---------|------|-----|-----|
| Synchronization | Asynchronous | Synchronous | Synchronous |
| Data flow | Full-duplex | Full-duplex | Half-duplex |
| Architecture | Point-to-point | Master-slave | Multi-master |
| Wiring | Fewer pins (no clock) | More pins (1 per slave) | 2 lines only (SDA + SCL) |
| Speed | Slower | High speed | Generally slower than SPI |
| Complexity | Simple and cost-effective | Versatile | Complex compared to UART and SPI |

---

## UART

- Asynchronous
- Full-duplex
- Simple and cost-effective
- Fewer pins required since no clock line is needed
- Only works as point-to-point communication, which limits scalability
- Slower compared to SPI

---

## SPI

- Synchronous
- Full-duplex
- Master-slave architecture
- High speed and versatile
- More pins required — each slave needs a dedicated chip-select pin

---

## I2C

- Synchronous
- Multi-master capable
- Half-duplex
- Two-wire interface: only 2 lines needed (SDA and SCL)
- Very simple wiring with multi-device support
- Generally slower than SPI and more complex compared to UART and SPI
