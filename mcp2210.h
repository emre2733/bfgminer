#ifndef BFG_MCP2210_H
#define BFG_MCP2210_H

#include <stdbool.h>

enum mcp2210_gpio_direction {
	MGD_OUTPUT,
	MGD_INPUT,
};

enum mcp2210_gpio_value {
	MGV_LOW,
	MGV_HIGH,
	MGV_ERROR,
};

struct mcp2210_device;

extern struct mcp2210_device *mcp2210_open(struct lowlevel_device_info *);
extern void mcp2210_close(struct mcp2210_device *);

extern bool mcp2210_configure_spi(struct mcp2210_device *, uint32_t bitrate, uint16_t idlechipsel, uint16_t activechipsel, uint16_t chipseltodatadelay, uint16_t lastbytetocsdelay, uint16_t midbytedelay);
extern bool mcp2210_set_spimode(struct mcp2210_device *, uint8_t spimode);
extern bool mcp2210_spi_transfer(struct mcp2210_device *, const void *tx, void *rx, uint8_t sz);

extern bool mcp2210_set_gpio_output(struct mcp2210_device *, int pin, enum mcp2210_gpio_value);
extern enum mcp2210_gpio_value mcp2210_get_gpio_input(struct mcp2210_device *, int pin);

#endif
