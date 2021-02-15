/* 
$clang -fsanitize=address -g index_out_bound.c -o a.out

index_out_bound.c:8:3: warning: array index 11 is past the end of the array (which contains 10 elements) [-Warray-bounds]
  a[11] = 1;
  ^ ~~
index_out_bound.c:6:3: note: array 'a' declared here
  int a[10] = {0};
  ^
1 warning generated.
*/
/*
$./a.out
=================================================================
==154589==ERROR: AddressSanitizer: stack-buffer-overflow on address 0x7fff3362f82c at pc 0x0000004c325f bp 0x7fff3362f7d0 sp 0x7fff3362f7c8
WRITE of size 4 at 0x7fff3362f82c thread T0
    #0 0x4c325e in main /home/taishan/leetcode/00_environment/AsanTest/index_out_bound.c:8:9
    #1 0x7f5b90b4f0b2 in __libc_start_main /build/glibc-eX1tMB/glibc-2.31/csu/../csu/libc-start.c:308:16
    #2 0x41b2dd in _start (/home/taishan/leetcode/00_environment/AsanTest/a.out+0x41b2dd)

Address 0x7fff3362f82c is located in stack of thread T0 at offset 76 in frame
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void){
  int a[10] = {0};

  a[11] = 1;
  return 0;


}
