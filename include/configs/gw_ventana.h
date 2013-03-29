/*
 * Copyright (C) 2013 Gateworks Corporation
 *
 * Configuration settings for the Freescale i.MX6Q Sabre Lite board.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.		See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_MX6
#define CONFIG_MX6Q              /* i.MX6Q CPU */
#define CONFIG_DISPLAY_CPUINFO   /* display cpu info */
#define CONFIG_DISPLAY_BOARDINFO /* display board info */

#define CONFIG_MACH_TYPE	4520   /* Gateworks Ventana Platform */

#include <asm/arch/imx-regs.h>
#include <asm/imx-common/gpio.h>

/* ATAGs */
#define CONFIG_CMDLINE_TAG
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG
#define CONFIG_SERIAL_TAG
#define CONFIG_REVISION_TAG

/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		(10 * 1024 * 1024)

/* Init Functions */
#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_MISC_INIT_R

/* GPIO */
#define CONFIG_MXC_GPIO

/* Serial */
#define CONFIG_MXC_UART
#define CONFIG_MXC_UART_BASE	       UART2_BASE

/* SPI */
#define CONFIG_CMD_SF
#ifdef CONFIG_CMD_SF
#define CONFIG_MXC_SPI
#define CONFIG_SPI_FLASH
#define CONFIG_SPI_FLASH_WINBOND
#define CONFIG_SPI_FLASH_WINBOND_ERASESIZE 64*1024  // 4,32,64K for W26Q256
#define CONFIG_SF_DEFAULT_BUS              0
#define CONFIG_SF_DEFAULT_CS               (0|(IMX_GPIO_NR(3, 19)<<8)) // GPIO 3-19 (21248)
#define CONFIG_SF_DEFAULT_SPEED            30000000
#define CONFIG_SF_DEFAULT_MODE             (SPI_MODE_0)
#endif

/* I2C Configs */
#define CONFIG_CMD_I2C
#define CONFIG_I2C_MULTI_BUS
#define CONFIG_I2C_MXC
#define CONFIG_SYS_I2C_SPEED		          100000

/* OCOTP Configs */
#define CONFIG_CMD_IMXOTP
#ifdef CONFIG_CMD_IMXOTP
#define CONFIG_IMX_OTP
#define IMX_OTP_BASE            OCOTP_BASE_ADDR
#define IMX_OTP_ADDR_MAX        0x7F
#define IMX_OTP_DATA_ERROR_VAL  0xBADABADA
#define IMX_OTPWRITE_ENABLED
#endif

/* PWM Configs */
#define CONFIG_IMX_PWM
#define IMX_PWM1_BASE    PWM1_BASE_ADDR
#define IMX_PWM2_BASE    PWM2_BASE_ADDR
#define IMX_PWM3_BASE    PWM3_BASE_ADDR
#define IMX_PWM4_BASE    PWM4_BASE_ADDR

/* MMC Configs */
#define CONFIG_FSL_ESDHC
#define CONFIG_FSL_USDHC
#define CONFIG_SYS_FSL_ESDHC_ADDR      0
#define CONFIG_SYS_FSL_USDHC_NUM       1
#define CONFIG_MMC
#define CONFIG_CMD_MMC
#define CONFIG_GENERIC_MMC
#define CONFIG_BOUNCE_BUFFER

/* Filesystem support */
#define CONFIG_DOS_PARTITION

/*
 * SATA Configs
 */
#define CONFIG_CMD_SATA
#ifdef CONFIG_CMD_SATA
#define CONFIG_DWC_AHSATA
#define CONFIG_SYS_SATA_MAX_DEVICE	1
#define CONFIG_DWC_AHSATA_PORT_ID	0
#define CONFIG_DWC_AHSATA_BASE_ADDR	SATA_ARB_BASE_ADDR
#define CONFIG_LBA48
#define CONFIG_LIBATA
#endif

/* Various command support */
#include <config_cmd_default.h>
#undef CONFIG_CMD_IMLS
#define CONFIG_CMD_PING
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_MII
#define CONFIG_CMD_NET
#define CONFIG_CMD_EXT2
#define CONFIG_CMD_FAT
#define CONFIG_CMD_BMODE /* set eFUSE shadow for a boot device and soft-reset */
#define CONFIG_CMD_BOOTZ

/* Ethernet support */
#define CONFIG_FEC_MXC
#define CONFIG_MII
#define IMX_FEC_BASE             ENET_BASE_ADDR
#define CONFIG_FEC_XCV_TYPE      RGMII
#define CONFIG_ETHPRIME          "FEC"
#define CONFIG_FEC_MXC_PHYADDR   0
#define CONFIG_PHYLIB
#define CONFIG_ARP_TIMEOUT       200UL

/* USB Configs */
#define CONFIG_CMD_USB
#define CONFIG_USB_EHCI
#define CONFIG_USB_EHCI_MX6
#define CONFIG_USB_STORAGE
#define CONFIG_USB_HOST_ETHER
#define CONFIG_USB_ETHER_ASIX
#define CONFIG_USB_ETHER_SMSC95XX
#define CONFIG_MXC_USB_PORT       1
#define CONFIG_MXC_USB_PORTSC     (PORT_PTS_UTMI | PORT_PTS_PTW)
#define CONFIG_MXC_USB_FLAGS      0

/* Framebuffer and LCD */
#define CONFIG_VIDEO
#define CONFIG_VIDEO_IPUV3
#define CONFIG_CFB_CONSOLE
#define CONFIG_VGA_AS_SINGLE_DEVICE
#define CONFIG_SYS_CONSOLE_IS_IN_ENV
#define CONFIG_SYS_CONSOLE_OVERWRITE_ROUTINE
#define CONFIG_VIDEO_BMP_RLE8
#define CONFIG_SPLASH_SCREEN
#define CONFIG_BMP_16BPP
#define CONFIG_VIDEO_LOGO
#define CONFIG_IPUV3_CLK          260000000

/* serial console (ttymxc1,115200) */
#define CONFIG_CONS_INDEX         1
#define CONFIG_BAUDRATE           115200
#define CONFIG_BOOTDELAY          3

#define CONFIG_EXTRA_ENV_SETTINGS \
	"script=boot.scr\0" \
	"console=ttymxc1\0" \
	"fdt_high=0xffffffff\0" \
	"ip_dyn=yes\0" \
	"serverip=192.168.1.146\0" \
	"ipaddr=192.168.1.1\0" \
	"root=/dev/mtdblock3 rootfstype=squashfs,jffs2\0" \
	"video=\0" \
	"video_hdmi=mxcfb0:dev=hdmi,1280x720M@60,if=RGB24\0" \
	"video_lvds1=mxcfb0:dev=ldb,LDB-XGA,if=RGB666\0" \
	"image=ventana/uImage\0" \
	"debug=debug\0" \
	\
	"bootnet=tftp 0x10800000 ventana/${image} && " \
		"setenv bootargs console=${console},${baudrate} root=${root} ${video} ${debug} && " \
		"bootm\0" \
	\
	"bootmmc=mmc dev 0 && sleep 1 && mmc rescan && " \
		"ext2load mmc 0:1 0x10800000 boot/${image} && " \
		"setenv bootargs console=${console},${baudrate} root=${root} ${video} ${debug} && " \
		"bootm\0" \
	\
	"clearenv=sf probe && " \
		"sf erase 0x80000 0x10000 && " \
		"echo resotred environment to factory defaults\0" \
	\
	"updateuboot=echo Updating uboot from ${serverip}:ventana/u-boot.imx ...; "\
		"tftpboot 0x10800000 ventana/u-boot.imx && " \
		"sf probe && " \
		"sf erase 0 0x80000 && " \
		"sf write 0x10800000 0x400 ${filesize}\0" 	\
	\
	"update=sf probe && " \
		"sf erase 0x00090000 0x0f70000 && " \
		"tftp 0x10800000 ventana/openwrt-imx61-imx6q-gw5400-squashfs.bin && " \
		"sf write 0x10800000 0x00090000 ${filesize}\0"

#define CONFIG_BOOTCOMMAND \
	"sf probe && " \
		"sf read 0x10800000 0x00090000 0x200000 && " \
		"setenv bootargs console=${console},${baudrate} root=${root} ${debug} && " \
		"bootm" 

/* Miscellaneous configurable options */
#define CONFIG_SYS_LONGHELP
#define CONFIG_SYS_HUSH_PARSER
#define CONFIG_SYS_PROMPT	             "Ventana > "
#define CONFIG_SYS_CBSIZE	             512
#define CONFIG_AUTO_COMPLETE
#define CONFIG_CMDLINE_EDITING

/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE (CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_MAXARGS	       16
#define CONFIG_SYS_BARGSIZE CONFIG_SYS_CBSIZE

/* Memory configuration */
#define CONFIG_SYS_MEMTEST_START       0x10000000
#define CONFIG_SYS_MEMTEST_END	       0x10010000
#define CONFIG_SYS_TEXT_BASE	         0x17800000
#define CONFIG_SYS_LOAD_ADDR           0x10800000
#define CONFIG_SYS_HZ                  1000

/* Physical Memory Map */
#define CONFIG_NR_DRAM_BANKS           1
#define PHYS_SDRAM                     MMDC0_ARB_BASE_ADDR
#define PHYS_SDRAM_SIZE                (1u * 1024 * 1024 * 1024)

#define CONFIG_SYS_SDRAM_BASE          PHYS_SDRAM
#define CONFIG_SYS_INIT_RAM_ADDR       IRAM_BASE_ADDR
#define CONFIG_SYS_INIT_RAM_SIZE       IRAM_SIZE

#define CONFIG_SYS_INIT_SP_OFFSET \
       (CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_ADDR \
       (CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_SP_OFFSET)

/* FLASH and environment organization */
#define CONFIG_SYS_NO_FLASH  // NOR flash

/* Persistent Environment Config */
#define CONFIG_ENV_OVERWRITE           /* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_SIZE                (8 * 1024)
#define CONFIG_ENV_IS_IN_SPI_FLASH
//#define CONFIG_ENV_IS_IN_MMC
#if defined(CONFIG_ENV_IS_IN_MMC)
#define CONFIG_ENV_OFFSET              (6 * 64 * 1024)
#define CONFIG_SYS_MMC_ENV_DEV         0
#elif defined(CONFIG_ENV_IS_IN_SPI_FLASH)
#define CONFIG_ENV_OFFSET              (512 * 1024)
#define CONFIG_ENV_SECT_SIZE           (64 * 1024)
#define CONFIG_ENV_SPI_BUS             CONFIG_SF_DEFAULT_BUS
#define CONFIG_ENV_SPI_CS              CONFIG_SF_DEFAULT_CS
#define CONFIG_ENV_SPI_MODE            CONFIG_SF_DEFAULT_MODE
#define CONFIG_ENV_SPI_MAX_HZ          CONFIG_SF_DEFAULT_SPEED
#endif

/* Flattened Image Tree Suport */
#define CONFIG_FIT
#define CONFIG_FIT_VERBOSE
#define CONFIG_OF_BOARD_SETUP
#define CONFIG_OF_LIBFDT

#ifndef CONFIG_SYS_DCACHE_OFF
#define CONFIG_CMD_CACHE
#endif

#endif			       /* __CONFIG_H */
