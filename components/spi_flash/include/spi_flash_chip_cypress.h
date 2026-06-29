// SmartSense fork: Cypress/Spansion S25FL256 chip driver header

#pragma once

#include <stdint.h>
#include "esp_flash.h"
#include "spi_flash_chip_driver.h"

/**
 * Cypress/Spansion SPI flash chip_drv. Provides native 4-byte address command
 * support for S25FLxxx parts larger than 16MB.
 */
extern const spi_flash_chip_t esp_flash_chip_cypress;

esp_err_t spi_flash_chip_cypress_read(esp_flash_t *chip, void *buffer, uint32_t address, uint32_t length);
esp_err_t spi_flash_chip_cypress_page_program(esp_flash_t *chip, const void *buffer, uint32_t address, uint32_t length);
esp_err_t spi_flash_chip_cypress_erase_sector(esp_flash_t *chip, uint32_t start_address);
esp_err_t spi_flash_chip_cypress_erase_block(esp_flash_t *chip, uint32_t start_address);
spi_flash_caps_t spi_flash_chip_cypress_get_caps(esp_flash_t *chip);
