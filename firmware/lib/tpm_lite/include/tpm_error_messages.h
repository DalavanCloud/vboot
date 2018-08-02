/* Copyright (c) 2010 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/* TPM error codes.
 *
 * Copy-pasted and lightly edited from TCG TPM Main Part 2 TPM Structures
 * Version 1.2 Level 2 Revision 103 26 October 2006 Draft.
 */

#ifndef TPM_ERROR_MESSAGES_H
#define TPM_ERROR_MESSAGES_H

#define TPM_E_BASE 0x0
#define TPM_E_NON_FATAL 0x800

typedef struct tpm_error_info {
	const char* name;
	uint32_t code;
	const char* description;
} tpm_error_info;

tpm_error_info tpm_error_table[] = {
{ "TPM_AUTHFAIL", TPM_E_BASE + 1,
"Authentication failed" },
{ "TPM_BADINDEX", TPM_E_BASE + 2,
"The index to a PCR, DIR or other register is incorrect" },
{ "TPM_BAD_PARAMETER", TPM_E_BASE + 3,
"One or more parameter is bad" },
{ "TPM_AUDITFAILURE", TPM_E_BASE + 4,
"An operation completed successfully\n\
but the auditing of that operation failed" },
{ "TPM_CLEAR_DISABLED", TPM_E_BASE + 5,
"The clear disable flag is set and all clear operations now require\n\
physical access" },
{ "TPM_DEACTIVATED", TPM_E_BASE + 6,
"The TPM is deactivated" },
{ "TPM_DISABLED", TPM_E_BASE + 7,
"The TPM is disabled" },
{ "TPM_DISABLED_CMD", TPM_E_BASE + 8,
"The target command has been disabled" },
{ "TPM_FAIL", TPM_E_BASE + 9,
"The operation failed" },
{ "TPM_BAD_ORDINAL", TPM_E_BASE + 10,
"The ordinal was unknown or inconsistent" },
{ "TPM_INSTALL_DISABLED", TPM_E_BASE + 11,
"The ability to install an owner is disabled" },
{ "TPM_INVALID_KEYHANDLE", TPM_E_BASE + 12,
"The key handle can not be interpreted" },
{ "TPM_KEYNOTFOUND", TPM_E_BASE + 13,
"The key handle points to an invalid key" },
{ "TPM_INAPPROPRIATE_ENC", TPM_E_BASE + 14,
"Unacceptable encryption scheme" },
{ "TPM_MIGRATEFAIL", TPM_E_BASE + 15,
"Migration authorization failed" },
{ "TPM_INVALID_PCR_INFO", TPM_E_BASE + 16,
"PCR information could not be interpreted" },
{ "TPM_NOSPACE", TPM_E_BASE + 17,
"No room to load key" },
{ "TPM_NOSRK", TPM_E_BASE + 18,
"There is no SRK set" },
{ "TPM_NOTSEALED_BLOB", TPM_E_BASE + 19,
"An encrypted blob is invalid or was not created by this TPM" },
{ "TPM_OWNER_SET", TPM_E_BASE + 20,
"There is already an Owner" },
{ "TPM_RESOURCES", TPM_E_BASE + 21,
"The TPM has insufficient internal resources to perform the requested action" },
{ "TPM_SHORTRANDOM", TPM_E_BASE + 22,
"A random string was too short" },
{ "TPM_SIZE", TPM_E_BASE + 23,
"The TPM does not have the space to perform the operation" },
{ "TPM_WRONGPCRVAL", TPM_E_BASE + 24,
"The named PCR value does not match the current PCR value" },
{ "TPM_BAD_PARAM_SIZE", TPM_E_BASE + 25,
"The paramSize argument to the command has the incorrect value" },
{ "TPM_SHA_THREAD", TPM_E_BASE + 26,
"There is no existing SHA-1 thread" },
{ "TPM_SHA_ERROR", TPM_E_BASE + 27,
"The calculation is unable to proceed because the existing SHA-1\n\
thread has already encountered an error" },
{ "TPM_FAILEDSELFTEST", TPM_E_BASE + 28,
"Self-test has failed and the TPM has shutdown" },
{ "TPM_AUTH2FAIL", TPM_E_BASE + 29,
"The authorization for the second key in a 2 key function\n\
failed authorization" },
{ "TPM_BADTAG", TPM_E_BASE + 30,
"The tag value sent to for a command is invalid" },
{ "TPM_IOERROR", TPM_E_BASE + 31,
"An IO error occurred transmitting information to the TPM" },
{ "TPM_ENCRYPT_ERROR", TPM_E_BASE + 32,
"The encryption process had a problem" },
{ "TPM_DECRYPT_ERROR", TPM_E_BASE + 33,
"The decryption process did not complete" },
{ "TPM_INVALID_AUTHHANDLE", TPM_E_BASE + 34,
"An invalid handle was used" },
{ "TPM_NO_ENDORSEMENT", TPM_E_BASE + 35,
"The TPM does not a EK installed" },
{ "TPM_INVALID_KEYUSAGE", TPM_E_BASE + 36,
"The usage of a key is not allowed" },
{ "TPM_WRONG_ENTITYTYPE", TPM_E_BASE + 37,
"The submitted entity type is not allowed" },
{ "TPM_INVALID_POSTINIT", TPM_E_BASE + 38,
"The command was received in the wrong sequence relative to TPM_Init\n\
and a subsequent TPM_Startup" },
{ "TPM_INAPPROPRIATE_SIG", TPM_E_BASE + 39,
"Signed data cannot include additional DER information" },
{ "TPM_BAD_KEY_PROPERTY", TPM_E_BASE + 40,
"The key properties in TPM_KEY_PARMs are not supported by this TPM" },
{ "TPM_BAD_MIGRATION", TPM_E_BASE + 41,
"The migration properties of this key are incorrect" },
{ "TPM_BAD_SCHEME", TPM_E_BASE + 42,
"The signature or encryption scheme for this key is incorrect or not\n\
permitted in this situation" },
{ "TPM_BAD_DATASIZE", TPM_E_BASE + 43,
"The size of the data (or blob) parameter is bad or inconsistent\n\
with the referenced key" },
{ "TPM_BAD_MODE", TPM_E_BASE + 44,
"A mode parameter is bad, such as capArea or subCapArea for\n\
TPM_GetCapability, physicalPresence parameter for TPM_PhysicalPresence,\n\
or migrationType for, TPM_CreateMigrationBlob" },
{ "TPM_BAD_PRESENCE", TPM_E_BASE + 45,
"Either the physicalPresence or physicalPresenceLock bits\n\
have the wrong value" },
{ "TPM_BAD_VERSION", TPM_E_BASE + 46,
"The TPM cannot perform this version of the capability" },
{ "TPM_NO_WRAP_TRANSPORT", TPM_E_BASE + 47,
"The TPM does not allow for wrapped transport sessions" },
{ "TPM_AUDITFAIL_UNSUCCESSFUL", TPM_E_BASE + 48,
"TPM audit construction failed and the underlying command\n\
was returning a failure code also" },
{ "TPM_AUDITFAIL_SUCCESSFUL", TPM_E_BASE + 49,
"TPM audit construction failed and the underlying command\n\
was returning success" },
{ "TPM_NOTRESETABLE", TPM_E_BASE + 50,
"Attempt to reset a PCR register that does not have the resettable attribute" },
{ "TPM_NOTLOCAL", TPM_E_BASE + 51,
"Attempt to reset a PCR register that requires locality\n\
and locality modifier not part of command transport" },
{ "TPM_BAD_TYPE", TPM_E_BASE + 52,
"Make identity blob not properly typed" },
{ "TPM_INVALID_RESOURCE", TPM_E_BASE + 53,
"When saving context identified resource type does not match actual resource" },
{ "TPM_NOTFIPS", TPM_E_BASE + 54,
"The TPM is attempting to execute a command only available when in FIPS mode" },
{ "TPM_INVALID_FAMILY", TPM_E_BASE + 55,
"The command is attempting to use an invalid family ID" },
{ "TPM_NO_NV_PERMISSION", TPM_E_BASE + 56,
"The permission to manipulate the NV storage is not available" },
{ "TPM_REQUIRES_SIGN", TPM_E_BASE + 57,
"The operation requires a signed command" },
{ "TPM_KEY_NOTSUPPORTED", TPM_E_BASE + 58,
"Wrong operation to load an NV key" },
{ "TPM_AUTH_CONFLICT", TPM_E_BASE + 59,
"NV_LoadKey blob requires both owner and blob authorization" },
{ "TPM_AREA_LOCKED", TPM_E_BASE + 60,
"The NV area is locked and not writable" },
{ "TPM_BAD_LOCALITY", TPM_E_BASE + 61,
"The locality is incorrect for the attempted operation" },
{ "TPM_READ_ONLY", TPM_E_BASE + 62,
"The NV area is read only and canât be written to" },
{ "TPM_PER_NOWRITE", TPM_E_BASE + 63,
"There is no protection on the write to the NV area" },
{ "TPM_FAMILYCOUNT", TPM_E_BASE + 64,
"The family count value does not match" },
{ "TPM_WRITE_LOCKED", TPM_E_BASE + 65,
"The NV area has already been written to" },
{ "TPM_BAD_ATTRIBUTES", TPM_E_BASE + 66,
"The NV area attributes conflict" },
{ "TPM_INVALID_STRUCTURE", TPM_E_BASE + 67,
"The structure tag and version are invalid or inconsistent" },
{ "TPM_KEY_OWNER_CONTROL", TPM_E_BASE + 68,
"The key is under control of the TPM Owner and can only be evicted\n\
by the TPM Owner" },
{ "TPM_BAD_COUNTER", TPM_E_BASE + 69,
"The counter handle is incorrect" },
{ "TPM_NOT_FULLWRITE", TPM_E_BASE + 70,
"The write is not a complete write of the area" },
{ "TPM_CONTEXT_GAP", TPM_E_BASE + 71,
"The gap between saved context counts is too large" },
{ "TPM_MAXNVWRITES", TPM_E_BASE + 72,
"The maximum number of NV writes without an owner has been exceeded" },
{ "TPM_NOOPERATOR", TPM_E_BASE + 73,
"No operator AuthData value is set" },
{ "TPM_RESOURCEMISSING", TPM_E_BASE + 74,
"The resource pointed to by context is not loaded" },
{ "TPM_DELEGATE_LOCK", TPM_E_BASE + 75,
"The delegate administration is locked" },
{ "TPM_DELEGATE_FAMILY", TPM_E_BASE + 76,
"Attempt to manage a family other then the delegated family" },
{ "TPM_DELEGATE_ADMIN", TPM_E_BASE + 77,
"Delegation table management not enabled" },
{ "TPM_TRANSPORT_NOTEXCLUSIVE", TPM_E_BASE + 78,
"There was a command executed outside of an exclusive transport session" },
{ "TPM_OWNER_CONTROL", TPM_E_BASE + 79,
"Attempt to context save a owner evict controlled key" },
{ "TPM_DAA_RESOURCES", TPM_E_BASE + 80,
"The DAA command has no resources available to execute the command" },
{ "TPM_DAA_INPUT_DATA0", TPM_E_BASE + 81,
"The consistency check on DAA parameter inputData0 has failed" },
{ "TPM_DAA_INPUT_DATA1", TPM_E_BASE + 82,
"The consistency check on DAA parameter inputData1 has failed" },
{ "TPM_DAA_ISSUER_SETTINGS", TPM_E_BASE + 83,
"The consistency check on DAA_issuerSettings has failed" },
{ "TPM_DAA_TPM_SETTINGS", TPM_E_BASE + 84,
"The consistency check on DAA_tpmSpecific has failed" },
{ "TPM_DAA_STAGE", TPM_E_BASE + 85,
"The atomic process indicated by the submitted DAA command is not\n\
the expected process" },
{ "TPM_DAA_ISSUER_VALIDITY", TPM_E_BASE + 86,
"The issuerâs validity check has detected an inconsistency" },
{ "TPM_DAA_WRONG_W", TPM_E_BASE + 87,
"The consistency check on w has failed" },
{ "TPM_BAD_HANDLE", TPM_E_BASE + 88,
"The handle is incorrect" },
{ "TPM_BAD_DELEGATE", TPM_E_BASE + 89,
"Delegation is not correct" },
{ "TPM_BADCONTEXT", TPM_E_BASE + 90,
"The context blob is invalid" },
{ "TPM_TOOMANYCONTEXTS", TPM_E_BASE + 91,
"Too many contexts held by the TPM" },
{ "TPM_MA_TICKET_SIGNATURE", TPM_E_BASE + 92,
"Migration authority signature validation failure" },
{ "TPM_MA_DESTINATION", TPM_E_BASE + 93,
"Migration destination not authenticated" },
{ "TPM_MA_SOURCE", TPM_E_BASE + 94,
"Migration source incorrect" },
{ "TPM_MA_AUTHORITY", TPM_E_BASE + 95,
"Incorrect migration authority" },
{ "TPM_PERMANENTEK", TPM_E_BASE + 97,
"Attempt to revoke the EK and the EK is not revocable" },
{ "TPM_BAD_SIGNATURE", TPM_E_BASE + 98,
"Bad signature of CMK ticket" },
{ "TPM_NOCONTEXTSPACE", TPM_E_BASE + 99,
"There is no room in the context list for additional contexts" },
{ "TPM_RETRY", TPM_E_BASE + TPM_E_NON_FATAL,
"The TPM is too busy to respond to the command immediately, but\n\
the command could be resubmitted at a later time.  The TPM MAY\n\
return TPM_RETRY for any command at any time" },
{ "TPM_NEEDS_SELFTEST", TPM_E_BASE + TPM_E_NON_FATAL + 1,
"TPM_ContinueSelfTest has not been run" },
{ "TPM_DOING_SELFTEST", TPM_E_BASE + TPM_E_NON_FATAL + 2,
"The TPM is currently executing the actions of TPM_ContinueSelfTest\n\
because the ordinal required resources that have not been tested" },
{ "TPM_DEFEND_LOCK_RUNNING", TPM_E_BASE + TPM_E_NON_FATAL + 3,
"The TPM is defending against dictionary attacks and is in some\n\
time-out period" },
};

#endif  /* TPM_ERROR_MESSAGES_H */
