#pragma once

#include <stdio.h>
#include <stdlib.h>

static FILE *vgdf = NULL;

static int should_dump_virgl(void) {
   static const char * virgl_dmp = NULL;
   if (!virgl_dmp) {
      virgl_dmp = getenv("DUMP_VIRGL");
      if (!virgl_dmp) virgl_dmp = "0";
   }
   return virgl_dmp[0] != '0';
}

static void dump_log(const char* msg) {
   if (should_dump_virgl()) {
      printf("%s", msg);
   }
}

static FILE *get_dump_file(void) {
   if (!vgdf) {
      vgdf = fopen("virgl.dump", "w");
      if (!vgdf) {
         printf("Failed to open vgdf file!\n");
         exit(1);
      }
      printf("Opened vgdf!\n");
   }
   return vgdf;
}
