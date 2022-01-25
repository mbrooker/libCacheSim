//
//  csvReader.h
//  libCacheSim
//
//  Created by Juncheng on 5/25/16.
//  Copyright © 2016 Juncheng. All rights reserved.
//

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include <inttypes.h>
#include <stdbool.h>

#include "../../include/libCacheSim/reader.h"

typedef struct {
  bool has_header;
  unsigned char delim;
  struct csv_parser *csv_parser;

  int current_field_counter;

  void *req_pointer;
  bool already_got_req;
  bool reader_end;

} csv_params_t;

void csv_setup_reader(reader_t *const reader);

int csv_read_one_element(reader_t *const, request_t *const);

uint64_t csv_skip_N_elements(reader_t *const reader, const uint64_t N);

void csv_reset_reader(reader_t *reader);

void csv_set_no_eof(reader_t *reader);

#ifdef __cplusplus
}
#endif

