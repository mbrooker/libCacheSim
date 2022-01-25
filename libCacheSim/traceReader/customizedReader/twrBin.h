/*
 * format
 *
 * struct {
 *  int32_t real_time;
 *  int64_t obj_id;
 *  int32_t key_size:10;
 *  int32_t value_size:22;
 *  int32_t op:8;
 *  int32_t ttl:24;
 *
 *  }
 *
 */


#pragma once

#include "../../include/libCacheSim/reader.h"
#include "binaryUtils.h"

#ifdef __cplusplus
extern "C" {
#endif

static inline int twrReader_setup(reader_t *reader) {
  reader->trace_type = TWR_TRACE;
  reader->trace_format = BINARY_TRACE_FORMAT;
  reader->item_size = 20;
  reader->n_total_req = (uint64_t) reader->file_size / (reader->item_size);
  return 0;
}

static int twr_read_one_req(reader_t *reader, request_t *req) {
  char *record = read_bytes(reader);

  if (record == NULL) {
    req->valid = FALSE;
    return 1;
  }

  req->real_time = *(uint32_t *) record;
  req->obj_id = *(uint64_t *) (record + 4);
  uint32_t kv_size = *(uint32_t *) (record + 12);
  uint32_t op_ttl = *(uint32_t *) (record + 16);

  uint32_t key_size = (kv_size >> 22) & (0x00000400 - 1);
  uint32_t val_size = kv_size & (0x00400000 - 1);

  uint32_t op = ((op_ttl >> 24) & (0x00000100 - 1));
  uint32_t ttl = op_ttl & (0x01000000 - 1);

  req->key_size = key_size;
  req->val_size = val_size;
  req->obj_size = key_size + val_size;
  req->op = (req_op_e) (op);
  req->ttl = (int32_t) ttl;

  if (req->val_size == 0 && reader->ignore_size_zero_req && (req->op == OP_GET || req->op == OP_GETS)) {
//    printf("skip \n");
    return twr_read_one_req(reader, req);
  }

//  printf("read %ld %llu %u %u %d %d\n", req->real_time, req->obj_id, req->key_size, req->val_size, req->op, req->ttl);
  return 0;
}

#ifdef __cplusplus
}
#endif









