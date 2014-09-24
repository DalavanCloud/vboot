/*
 * Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#ifndef VBOOT_REFERENCE_FUTILITY_TRAVERSAL_H_
#define VBOOT_REFERENCE_FUTILITY_TRAVERSAL_H_
#include <stdint.h>


/* What type of things do I know how to handle? */
enum futil_file_type {
	FILE_TYPE_UNKNOWN,
	FILE_TYPE_PUBKEY,			/* 1 VbPublicKey */
	FILE_TYPE_KEYBLOCK,			/* 2 VbKeyBlockHeader */
	FILE_TYPE_FW_PREAMBLE,			/* 3 VbFirmwarePreambleHeader */
	FILE_TYPE_GBB,				/* 4 GoogleBinaryBlockHeader */
	FILE_TYPE_BIOS_IMAGE,			/* 5 Chrome OS BIOS image */
	FILE_TYPE_OLD_BIOS_IMAGE,		/* 6 Old Chrome OS BIOS image */
	FILE_TYPE_KERN_PREAMBLE,		/* 7 VbKernelPreambleHeader */

	/* These are FILE_TYPE_UNKNOWN, but we've been told more about them */
	FILE_TYPE_RAW_FIRMWARE,			/* 8 FW_MAIN_A, etc. */
	FILE_TYPE_RAW_KERNEL,			/* 9 vmlinuz, *.uimg, etc. */

	NUM_FILE_TYPES
};

/* Names for them */
extern const char * const futil_file_type_str[];

/* What are we trying to accomplish? */
enum futil_op_type {
	FUTIL_OP_SHOW,
	FUTIL_OP_SIGN,

	NUM_FUTIL_OPS
};

/* What component are we currently handling in the callback routine? */
enum futil_cb_component {
	/* entire input buffer */
	CB_BEGIN_TRAVERSAL,
	CB_END_TRAVERSAL,
	/* fmap areas within a bios image */
	CB_FMAP_GBB,
	CB_FMAP_VBLOCK_A,
	CB_FMAP_VBLOCK_B,
	CB_FMAP_FW_MAIN_A,
	CB_FMAP_FW_MAIN_B,
	/* individual files (extracted from a bios, for example) */
	CB_PUBKEY,
	CB_KEYBLOCK,
	CB_GBB,
	CB_FW_PREAMBLE,
	CB_KERN_PREAMBLE,
	CB_RAW_FIRMWARE,
	CB_RAW_KERNEL,

	NUM_CB_COMPONENTS
};

/* Names for them */
extern const char * const futil_cb_component_str[];


/* Where is the component we're poking at? */
struct cb_area_s {
	uint32_t offset;			/* to avoid pointer math */
	uint8_t *buf;
	uint32_t len;
	uint32_t _flags;			/* for callback use */
};

/* What do we know at this point in time? */
struct futil_traverse_state_s {
	/* These two should be initialized by the caller as needed */
	const char *in_filename;
	enum futil_op_type op;
	/* Current activity during traversal */
	enum futil_cb_component component;
	struct cb_area_s *my_area;
	const char *name;
	/* Other activites, possibly before or after the current one */
	struct cb_area_s cb_area[NUM_CB_COMPONENTS];
	struct cb_area_s recovery_key;
	struct cb_area_s rootkey;
	enum futil_file_type in_type;
	int errors;
};


/*
 * This tries to match the buffer content to one of the known file types.
 */
enum futil_file_type futil_what_file_type_buf(uint8_t *buf, uint32_t len);

/*
 * This opens a file and tries to match it to one of the known file types. It
 * fails only if it can't open and scan the file. It's not an error if it
 * returns FILE_TYPE_UKNOWN.
 */
enum futil_file_type futil_what_file_type(const char *filename);

/*
 * Traverse the buffer using the provided state, which should be initialized
 * before calling. Returns nonzero (but no details) if there were any errors.
 */
int futil_traverse(uint8_t *buf, uint32_t len,
		   struct futil_traverse_state_s *state,
		   enum futil_file_type type_hint);

/* These are invoked by the traversal. They also return nonzero on error. */
int futil_cb_show_begin(struct futil_traverse_state_s *state);
int futil_cb_show_key(struct futil_traverse_state_s *state);
int futil_cb_show_gbb(struct futil_traverse_state_s *state);
int futil_cb_show_keyblock(struct futil_traverse_state_s *state);
int futil_cb_show_fw_main(struct futil_traverse_state_s *state);
int futil_cb_show_fw_preamble(struct futil_traverse_state_s *state);
int futil_cb_show_kernel_preamble(struct futil_traverse_state_s *state);

int futil_cb_sign_pubkey(struct futil_traverse_state_s *state);
int futil_cb_sign_fw_main(struct futil_traverse_state_s *state);
int futil_cb_sign_fw_vblock(struct futil_traverse_state_s *state);
int futil_cb_sign_raw_firmware(struct futil_traverse_state_s *state);
int futil_cb_resign_kernel_part(struct futil_traverse_state_s *state);
int futil_cb_create_kernel_part(struct futil_traverse_state_s *state);
int futil_cb_sign_begin(struct futil_traverse_state_s *state);
int futil_cb_sign_end(struct futil_traverse_state_s *state);


#endif /* VBOOT_REFERENCE_FUTILITY_TRAVERSAL_H_ */
