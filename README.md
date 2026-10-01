# Drone Battery Monitor

Small C project for checking a drone battery level and estimating remaining flight time.

## What It Does

- Reads a battery percentage.
- Detects `OK`, `LOW`, and `CRITICAL` battery states.
- Estimates remaining flight time from current power consumption.
- Prints a clear safety message for the pilot.

## What I Practice

- Variables and data types
- `if / else`
- `switch`
- Functions
- `enum`
- Clean terminal output

## Build And Run

```sh
make
./drone-battery-monitor
```

## Example

```text
Battery: 18%
Status: LOW
Estimated flight time: 5.4 minutes
Warning: return to home soon.
```
