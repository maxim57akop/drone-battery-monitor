#include <stdio.h>

typedef enum {
    BATTERY_OK,
    BATTERY_LOW,
    BATTERY_CRITICAL
} BatteryStatus;

static BatteryStatus get_battery_status(int battery_percent)
{
    if (battery_percent <= 10) {
        return BATTERY_CRITICAL;
    }

    if (battery_percent <= 25) {
        return BATTERY_LOW;
    }

    return BATTERY_OK;
}

static const char *battery_status_name(BatteryStatus status)
{
    switch (status) {
    case BATTERY_OK:
        return "OK";
    case BATTERY_LOW:
        return "LOW";
    case BATTERY_CRITICAL:
        return "CRITICAL";
    default:
        return "UNKNOWN";
    }
}

static double estimate_flight_time(int battery_percent, double minutes_at_full_battery)
{
    return (battery_percent / 100.0) * minutes_at_full_battery;
}

static void print_safety_message(BatteryStatus status)
{
    switch (status) {
    case BATTERY_OK:
        printf("Message: battery level is safe for normal flight.\n");
        break;
    case BATTERY_LOW:
        printf("Warning: return to home soon.\n");
        break;
    case BATTERY_CRITICAL:
        printf("Danger: land immediately.\n");
        break;
    default:
        printf("Message: unable to read battery status.\n");
        break;
    }
}

int main(void)
{
    int battery_percent = 18;
    double full_battery_flight_minutes = 30.0;
    BatteryStatus status = get_battery_status(battery_percent);

    printf("Battery: %d%%\n", battery_percent);
    printf("Status: %s\n", battery_status_name(status));
    printf("Estimated flight time: %.1f minutes\n",
           estimate_flight_time(battery_percent, full_battery_flight_minutes));
    print_safety_message(status);

    return 0;
}
