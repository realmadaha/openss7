/*****************************************************************************

 @(#) $Id$

 -----------------------------------------------------------------------------

 Copyright (c) 2008-2009  Monavacon Limited <http://www.monavacon.com/>
 Copyright (c) 2001-2008  OpenSS7 Corporation <http://www.openss7.com/>
 Copyright (c) 1997-2001  Brian F. G. Bidulock <bidulock@openss7.org>

 All Rights Reserved.

 This program is free software; you can redistribute it and/or modify it under
 the terms of the GNU Affero General Public License as published by the Free
 Software Foundation; version 3 of the License.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
 details.

 You should have received a copy of the GNU Affero General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>, or
 write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA
 02139, USA.

 -----------------------------------------------------------------------------

 U.S. GOVERNMENT RESTRICTED RIGHTS.  If you are licensing this Software on
 behalf of the U.S. Government ("Government"), the following provisions apply
 to you.  If the Software is supplied by the Department of Defense ("DoD"), it
 is classified as "Commercial Computer Software" under paragraph 252.227-7014
 of the DoD Supplement to the Federal Acquisition Regulations ("DFARS") (or any
 successor regulations) and the Government is acquiring only the license rights
 granted herein (the license rights customarily provided to non-Government
 users).  If the Software is supplied to any unit or agency of the Government
 other than DoD, it is classified as "Restricted Computer Software" and the
 Government's rights in the Software are defined in paragraph 52.227-19 of the
 Federal Acquisition Regulations ("FAR") (or any successor regulations) or, in
 the cases of NASA, in paragraph 18.52.227-86 of the NASA Supplement to the FAR
 (or any successor regulations).

 -----------------------------------------------------------------------------

 Commercial licensing and support of this software is available from OpenSS7
 Corporation at a fee.  See http://www.openss7.com/

 -----------------------------------------------------------------------------

 Last Modified $Date$ by $Author$

 -----------------------------------------------------------------------------

 $Log$
 *****************************************************************************/

#ifndef __LOCAL_DL_H__
#define __LOCAL_DL_H__

#ident "@(#) $RCSfile$ $Name$($Revision$) Copyright (c) 2008-2009 Monavacon Limited."

/* Events */

/* Events generated by the DLS User. */

#define DLE_INFO_REQ			0x00	/* Information Req */
#define DLE_ATTACH_REQ			0x01	/* Attach a PPA */
#define DLE_DETACH_REQ			0x02	/* Detach a PPA */
#define DLE_BIND_REQ			0x03	/* Bind dlsap address */
#define DLE_UNBIND_REQ			0x04	/* Unbind dlsap address */
#define DLE_SUBS_BIND_REQ		0x05	/* Bind Subsequent DLSAP address */
#define DLE_SUBS_UNBIND_REQ		0x06	/* Subsequent unbind */
#define DLE_ENABMULTI_REQ		0x07	/* Enable multicast addresses */
#define DLE_DISABMULTI_REQ		0x08	/* Disable multicast addresses */
#define DLE_PROMISCON_REQ		0x09	/* Turn on promiscuous mode */
#define DLE_PROMISCOFF_REQ		0x0a	/* Turn off promiscuous mode */
#define DLE_UNITDATA_REQ		0x0b	/* datagram send request */
#define DLE_UDQOS_REQ			0x0c	/* set QOS for subsequent datagrams */
#define DLE_CONNECT_REQ			0x0d	/* Connect request */
#define DLE_CONNECT_RES			0x0e	/* Accept previous connect indication */
#define DLE_TOKEN_REQ			0x0f	/* Passoff token request */
#define DLE_DISCONNECT_REQ		0x10	/* Disconnect request */
#define DLE_RESET_REQ			0x11	/* Reset service request */
#define DLE_RESET_RES			0x12	/* Complete reset processing */
#define DLE_DATA_ACK_REQ		0x13	/* data unit transmission request */
#define DLE_REPLY_REQ			0x14	/* Request a DLSDU from the remote */
#define DLE_REPLY_UPDATE_REQ		0x15	/* Hold a DLSDU for transmission */
#define DLE_XID_REQ			0x16	/* Request to send an XID PDU */
#define DLE_XID_RES			0x17	/* request to send a response XID PDU */
#define DLE_TEST_REQ			0x18	/* TEST command request */
#define DLE_TEST_RES			0x19	/* TEST response */
#define DLE_PHYS_ADDR_REQ		0x1a	/* Request to get physical addr */
#define DLE_SET_PHYS_ADDR_REQ		0x1b	/* set physical addr */
#define DLE_GET_STATISTICS_REQ		0x1c	/* Request to get statistics */

/* Events generated by the DLS Provider */

#define DLE_UNITDATA_IND		0x20	/* datagram receive indication */
#define DLE_UDERROR_IND			0x21	/* datagram error indication */
#define DLE_CONNECT_IND			0x22	/* Incoming connect indication */
#define DLE_CONNECT_CON			0x23	/* Connection established */
#define DLE_DISCONNECT_IND		0x24	/* Disconnect indication */
#define DLE_RESET_IND			0x25	/* Incoming reset indication */
#define DLE_RESET_CON			0x26	/* Reset processing complete */
#define DLE_DATA_ACK_IND		0x27	/* Arrival of a command PDU */
#define DLE_DATA_ACK_STATUS_IND		0x28	/* Status indication of DATA_ACK_REQ */
#define DLE_REPLY_IND			0x29	/* Arrival of a command PDU */
#define DLE_REPLY_STATUS_IND		0x2a	/* Status indication of REPLY_REQ */
#define DLE_REPLY_UPDATE_STATUS_IND	0x2b	/* Status of REPLY_UPDATE req */
#define DLE_XID_IND			0x2c	/* Arrival of an XID PDU */
#define DLE_XID_CON			0x2d	/* Arrival of a response XID PDU */
#define DLE_TEST_IND			0x2e	/* TEST response indication */
#define DLE_TEST_CON			0x2f	/* TEST Confirmation */

struct dl;

/* Event structures */

struct dle_info_req {
	dl_ulong dl_event;
	size_t dl_addr_length;
	caddr_t dl_addr_buffer;
	size_t dl_qos_length;
	caddr_t dl_qos_buffer;
	size_t dl_qos_range_length;
	caddr_t dl_qos_range_buffer;
	size_t dl_brdcst_addr_length;
	caddr_t dl_brdcst_addr_buffer;
};
struct dle_attach_req {
	dl_ulong dl_event;
	dl_ulong dl_ppa;
};
struct dle_detach_req {
	dl_ulong dl_event;
};
struct dle_bind_req {
	dl_ulong dl_event;
	dl_ulong dl_sap;
	dl_ulong dl_max_conind;
	dl_ushort dl_service_mode;
	dl_ushort dl_conn_mgmt;
	dl_ulong dl_xidtest_flg;
	size_t dl_addr_length;
	caddr_t dl_addr_buffer;
};
struct dle_unbind_req {
	dl_ulong dl_event;
};
struct dle_subs_bind_req {
	dl_ulong dl_event;
	size_t dl_subs_sap_length;
	caddr_t dl_subs_sap_buffer;
	dl_ulong dl_subs_bind_class;
};
struct dle_subs_unbind_req {
	dl_ulong dl_event;
	size_t dl_subs_sap_length;
	caddr_t dl_subs_sap_buffer;
};
struct dle_enabmulti_req {
	dl_ulong dl_event;
	size_t dl_addr_length;
	caddr_t dl_addr_buffer;
};
struct dle_disabmulti_req {
	dl_ulong dl_event;
	size_t dl_addr_length;
	caddr_t dl_addr_buffer;
};
struct dle_promiscon_req {
	dl_ulong dl_event;
	dl_ulong dl_level;
};
struct dle_promiscoff_req {
	dl_ulong dl_event;
	dl_ulong dl_level;
};
struct dle_unitdata_req {
	dl_ulong dl_event;
	size_t dl_dest_addr_length;
	caddr_t dl_dest_addr_buffer;
	dl_priority_t dl_priority;
	mblk_t *dl_data_blocks;
	size_t dl_data_length;
};
struct dle_udqos_req {
	dl_ulong dl_event;
	size_t dl_qos_length;
	caddr_t dl_qos_buffer;
};
struct dle_connect_req {
	dl_ulong dl_event;
	size_t dl_dest_addr_length;
	caddr_t dl_dest_addr_buffer;
	size_t dl_qos_length;
	caddr_t dl_qos_buffer;
};
struct dle_connect_res {
	dl_ulong dl_event;
	mblk_t *dl_correlation;
	struct dl *dl_resp_token;
	size_t dl_qos_length;
	caddr_t dl_qos_buffer;
};
struct dle_token_req {
	dl_ulong dl_event;
};
struct dle_disconnect_req {
	dl_ulong dl_event;
	dl_ulong dl_reason;
	mblk_t *dl_correlation;
};
struct dle_reset_req {
	dl_ulong dl_event;
};
struct dle_reset_res {
	dl_ulong dl_event;
};
struct dle_data_ack_req {
	dl_ulong dl_event;
	dl_ulong dl_correlation;
	size_t dl_dest_addr_length;
	caddr_t dl_dest_addr_buffer;
	size_t dl_src_addr_length;
	caddr_t dl_src_addr_buffer;
	dl_ulong dl_priority;
	dl_ulong dl_service_class;
	mblk_t *dl_data_blocks;
	size_t dl_data_length;
};
struct dle_reply_req {
	dl_ulong dl_event;
	dl_ulong dl_correlation;
	size_t dl_dest_addr_length;
	caddr_t dl_dest_addr_buffer;
	size_t dl_src_addr_length;
	caddr_t dl_src_addr_buffer;
	dl_ulong dl_priority;
	dl_ulong dl_service_class;
	mblk_t *dl_data_blocks;
	size_t dl_data_length;
};
struct dle_reply_update_req {
	dl_ulong dl_event;
	dl_ulong dl_correlation;
	size_t dl_src_addr_length;
	caddr_t dl_src_addr_buffer;
	mblk_t *dl_data_blocks;
	size_t dl_data_length;
};
struct dle_xid_req {
	dl_ulong dl_event;
	dl_ulong dl_flag;
	size_t dl_dest_addr_length;
	caddr_t dl_dest_addr_buffer;
	mblk_t *dl_data_blocks;
	size_t dl_data_length;
};
struct dle_xid_res {
	dl_ulong dl_event;
	dl_ulong dl_flag;
	size_t dl_dest_addr_length;
	caddr_t dl_dest_addr_buffer;
	mblk_t *dl_data_blocks;
	size_t dl_data_length;
};
struct dle_test_req {
	dl_ulong dl_event;
	dl_ulong dl_flag;
	size_t dl_dest_addr_length;
	caddr_t dl_dest_addr_buffer;
	mblk_t *dl_data_blocks;
	size_t dl_data_length;
};
struct dle_test_res {
	dl_ulong dl_event;
	dl_ulong dl_flag;
	size_t dl_dest_addr_length;
	caddr_t dl_dest_addr_buffer;
	mblk_t *dl_data_blocks;
	size_t dl_data_length;
};
struct dle_phys_addr_req {
	dl_ulong dl_event;
	dl_ulong dl_addr_type;
	size_t dl_addr_length;
	caddr_t dl_addr_buffer;
};
struct dle_set_phys_addr_req {
	dl_ulong dl_event;
	size_t dl_addr_length;
	caddr_t dl_addr_buffer;
};
struct dle_get_statistics_req {
	dl_ulong dl_event;
	size_t dl_stat_length;
	caddr_t dl_stat_buffer;
};

struct dle_unitdata_ind {
	dl_ulong dl_event;
	size_t dl_dest_addr_length;
	caddr_t dl_dest_addr_buffer;
	size_t dl_src_addr_length;
	caddr_t dl_src_addr_buffer;
	dl_ulong dl_group_address;
	mblk_t *dl_data_blocks;
	size_t dl_data_length;
};
struct dle_uderror_ind {
	dl_ulong dl_event;
	size_t dl_dest_addr_length;
	caddr_t dl_dest_addr_buffer;
	dl_ulong dl_unix_errno;
	dl_ulong dl_errno;
	mblk_t *dl_data_blocks;
	size_t dl_data_length;
};
struct dle_connect_ind {
	dl_ulong dl_event;
	dl_ulong dl_correlation;
	size_t dl_called_addr_length;
	caddr_t dl_called_addr_buffer;
	size_t dl_calling_addr_length;
	caddr_t dl_calling_addr_buffer;
	size_t dl_qos_length;
	caddr_t dl_qos_buffer;
	mblk_t *dl_data_blocks;
	size_t dl_data_length;
};
struct dle_connect_con {
	dl_ulong dl_event;
	size_t dl_resp_addr_length;
	caddr_t dl_resp_addr_buffer;
	size_t dl_qos_length;
	caddr_t dl_qos_buffer;
	mblk_t *dl_data_blocks;
	size_t dl_data_length;
};
struct dle_disconnect_ind {
	dl_ulong dl_event;
	dl_ulong dl_originator;
	dl_ulong dl_reason;
	mblk_t *dl_correlation;
	mblk_t *dl_data_blocks;
	size_t dl_data_length;
};
struct dle_reset_ind {
	dl_ulong dl_event;
	dl_ulong dl_originator;
	dl_ulong dl_reason;
};
struct dle_reset_con {
	dl_ulong dl_event;
};
struct dle_data_ack_ind {
	dl_ulong dl_event;
	size_t dl_dest_addr_length;
	caddr_t dl_dest_addr_buffer;
	size_t dl_src_addr_length;
	caddr_t dl_src_addr_buffer;
	dl_ulong dl_priority;
	dl_ulong dl_service_class;
	mblk_t *dl_data_blocks;
	size_t dl_data_length;
};
struct dle_data_ack_status_ind {
	dl_ulong dl_event;
	mblk_t *dl_correlation;
	dl_ulong dl_status;
};
struct dle_reply_ind {
	dl_ulong dl_event;
	size_t dl_dest_addr_length;
	caddr_t dl_dest_addr_buffer;
	size_t dl_src_addr_length;
	caddr_t dl_src_addr_buffer;
	dl_ulong dl_priority;
	dl_ulong dl_service_class;
	mblk_t *dl_data_blocks;
	size_t dl_data_length;
};
struct dle_reply_status_ind {
	dl_ulong dl_event;
	mblk_t *dl_correlation;
	dl_ulong dl_status;
	mblk_t *dl_data_blocks;
	size_t dl_data_length;
};
struct dle_reply_update_status_ind {
	dl_ulong dl_event;
	mblk_t *dl_correlation;
	dl_ulong dl_status;
};
struct dle_xid_ind {
	dl_ulong dl_event;
	dl_ulong dl_flag;
	size_t dl_dest_addr_length;
	caddr_t dl_dest_addr_buffer;
	size_t dl_src_addr_length;
	caddr_t dl_src_addr_buffer;
	mblk_t *dl_data_blocks;
	size_t dl_data_length;
};
struct dle_xid_con {
	dl_ulong dl_event;
	dl_ulong dl_flag;
	size_t dl_dest_addr_length;
	caddr_t dl_dest_addr_buffer;
	size_t dl_src_addr_length;
	caddr_t dl_src_addr_buffer;
	mblk_t *dl_data_blocks;
	size_t dl_data_length;
};
struct dle_test_ind {
	dl_ulong dl_event;
	dl_ulong dl_flag;
	size_t dl_dest_addr_length;
	caddr_t dl_dest_addr_buffer;
	size_t dl_src_addr_length;
	caddr_t dl_src_addr_buffer;
	mblk_t *dl_data_blocks;
	size_t dl_data_length;
};
struct dle_test_con {
	dl_ulong dl_event;
	dl_ulong dl_flag;
	size_t dl_dest_addr_length;
	caddr_t dl_dest_addr_buffer;
	size_t dl_src_addr_length;
	caddr_t dl_src_addr_buffer;
	mblk_t *dl_data_blocks;
	size_t dl_data_length;
};

union dl_event {
	dl_ulong event;
	struct dle_info_req info_req;
	struct dle_attach_req attach_req;
	struct dle_detach_req detach_req;
	struct dle_bind_req bind_req;
	struct dle_unbind_req unbind_req;
	struct dle_subs_bind_req subs_bind_req;
	struct dle_subs_unbind_req subs_unbind_req;
	struct dle_enabmulti_req enabmulti_req;
	struct dle_disabmulti_req disabmulti_req;
	struct dle_promiscon_req promiscon_req;
	struct dle_promiscoff_req promiscoff_req;
	struct dle_unitdata_req unitdata_req;
	struct dle_udqos_req udqos_req;
	struct dle_connect_req connect_req;
	struct dle_connect_res connect_res;
	struct dle_token_req token_req;
	struct dle_disconnect_req disconnect_req;
	struct dle_reset_req reset_req;
	struct dle_reset_res reset_res;
	struct dle_data_ack_req data_ack_req;
	struct dle_reply_req reply_req;
	struct dle_reply_update_req update_req;
	struct dle_xid_req xid_req;
	struct dle_xid_res xid_res;
	struct dle_test_req test_req;
	struct dle_test_res test_res;
	struct dle_phys_addr_req phys_addr_req;
	struct dle_set_phys_addr_req set_phys_addr_req;
	struct dle_get_statistics_req get_statistics_req;
	struct dle_unitdata_ind unitdata_ind;
	struct dle_uderror_ind uderror_ind;
	struct dle_connect_ind connect_ind;
	struct dle_connect_con connect_con;
	struct dle_disconnect_ind disconnect_ind;
	struct dle_reset_ind reset_ind;
	struct dle_reset_con reset_con;
	struct dle_data_ack_ind data_ack_ind;
	struct dle_data_ack_status_ind status_ind;
	struct dle_reply_ind reply_ind;
	struct dle_reply_status_ind reply_status_ind;
	struct dle_reply_update_status_ind update_status_ind;
	struct dle_xid_ind xid_ind;
	struct dle_xid_con xid_con;
	struct dle_test_ind test_ind;
	struct dle_test_con test_con;
};

#endif				/* __LOCAL_DL_H__ */