## Current Workflow Status

![example workflow](https://github.com/uofu-emb/2024_lab5_Noah_L_Chase/actions/workflows/main.yml/badge.svg)

# Lab 5 realtime (Noah Lomu, Chase Griswold)

# Part 1: Initial Observations
**task_delay.c**
Expected period: 1.000000 s
Observed period: 1.000008 s, Drift over 1 hr: 28.8 ms
Observed period with busy loop: 1.004004 s, Drift over 1 hr: 14.414 s

**timer.c**
Expected period: 1.000000 s
Observed period: 1.000008 s, Drift over 1 hr: 28.8 ms
Observed period with busy loop: 1.000008 s, Drift over 1 hr: 28.8 ms

**sleep.c**
Expected period: 1.000000 s
Observed period: 1.000008 s, Drift over 1 hr: 28.8 ms
Observed period with busy loop: 1.002492 s, Drift over 1 hr: 8.971 s

# Part 2: Sync Signal
**gpio_interrupt.c**
Without a busy task there was no delay between the sync signal and the response. Jitter was
3.42 microseconds.
With the busy loop added, there is now 1.242 ms of delay between the sync signal and the 
response, and jitter of 4.32 microseconds.

