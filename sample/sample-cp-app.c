/*
 * Copyright (c) 2019 Siddharth Chandrasekaran
 *
 * SPDX-License-Identifier: MIT
 */

#include <osdp.h>

enum osdp_pd_e
{
	OSDP_PD_1,
	OSDP_PD_2,
	OSDP_PD_SENTINEL,
};

int sample_cp_send_func(uint8_t *buf, int len)
{
	return len;
}

int sample_cp_recv_func(uint8_t *buf, int len)
{
	return 0;
}

int main()
{
	osdp_pd_info_t info[OSDP_PD_SENTINEL] = {
		[OSDP_PD_1] = {
			.address = 101,
			.baud_rate = 9600,
			.init_flags = 0,
			.send_func = sample_cp_send_func,
			.recv_func = sample_cp_recv_func},
		[OSDP_PD_2] = {
			.address = 102,
			.baud_rate = 9600,
			.init_flags = 0,
			.send_func = sample_cp_send_func,
			.recv_func = sample_cp_recv_func
		},
	};

	struct osdp_cp *ctx = osdp_cp_setup(OSDP_PD_SENTINEL, info);

	if (ctx == NULL)
	{
		printf("cp init failed!\n");
		return -1;
	}
	// osdp_set_log_level(LOG_DEBUG);

	while (1)
	{
		// your application code.

		osdp_cp_refresh(ctx);
	}
	return 0;
}