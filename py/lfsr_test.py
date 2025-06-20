if __name__ == "__main__":
    start_state = 0x5  # Initial state for the LFSR
    lfsr = start_state
    for i in range(1000000):
        print(f"{lfsr:016b} {lfsr:05d}")
        bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1
        lfsr = ((lfsr >> 1) | (bit << 15)) & 0xffff
        if (lfsr == start_state):
            print(i)
            break