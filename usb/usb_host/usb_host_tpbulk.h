/*
 * usb_host_tpbulk.h
 *
 *  Created on: 2013��10��25��
 *      Author: jingcunxu
 */

#ifndef USB_HOST_TPBULK_H_
#define USB_HOST_TPBULK_H_


//struct for CBW
typedef struct _COMMAND_BLOCK_WRAPPER
{
    u32   cbw_signature;
    u32   cbw_tag;
    u32   cbw_data_xferlen;
    u8    cbw_flag;
    u8    cbw_lun;
    u8    cbw_cbdlen;
    u8    operation_code;
    u8    reserve;
    u8    cbw_cblba[4];
    u8    reserve1;
    u16   cbw_cblength;
    u8    control;
    u8    reserved[6];
} CBW, *PCBW;


//struct for  CSW
typedef struct _COMMAND_STATUS_WRAPPER
{
    u32   csw_signature;
    u32   csw_tag;
    u32   csw_data_residue;
    u8    csw_status;
} CSW, *PCSW;


//command buffer for CBW or CSW
typedef union _TPBULK_STRUC
{
    CBW     cbw_val;
    CSW     csw_val;
    u8 		bulk_buf[64];

}TPBLK_STRUC, * PTPBLK_STRUC;


#define BULKTX_EP	1
#define BULKRX_EP	1


#define HOST_DMA_TX		1
#define HOST_DMA_RX		0

#define TT_ILLEGAL              (0 << 4)
#define TT_ISOCHRONOUS          (1 << 4)
#define TT_BULK                 (2 << 4)
#define TT_INTERRUPT            (3 << 4)

#define CBW_SIGNATURE   0x43425355
#define CSW_SIGNATURE   0x43425355
#define CBW_TAG         0xde24a660


#define tpbulk_cbw          tpbulk_block.cbw_val
#define tpbulk_csw          tpbulk_block.csw_val


#define	INQUIRY					0x12
#define READ_CAPACITY			0x25
#define READ_FORMAT_CAPACITIES	0x23
#define READ_DATA				0x28
#define WRITE_DATA				0x2A
#define MODE_SENSE				0x5A
#define REQUEST_SENSE			0x03

TPBLK_STRUC  tpbulk_block;
u8  pkt_per_sec;


u8 enum_mass_dev(void);
u8 rbc_read_lba(u8 *buffer2,u32 lba,u16 len);
u8 rbc_write_lba(u8 *buffer,u32 lba,u16 len);

#endif /* USB_HOST_TPBULK_H_ */
