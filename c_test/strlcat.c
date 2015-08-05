#include <string.h>
#include <stdio.h>

/// xstrlcat - appends string src to the end of dst.
///
/// Compatible with *BSD strlcat: It will append at most 
/// dstsize - strlen(dst) - 1 characters. 
/// It will then NUL-terminate, unless dstsize is 0 or 
/// the original dst string was longer than dstsize 
/// (in practice this should not happen as it means 
/// that either dstsize is incorrect or that dst is not a proper string).
///
/// @param dst Where to copy the string to
/// @param src Where to copy the string from
/// @param size Size of destination buffer
/// @return the initial length of dst plus the length of src. (i.e.:: strlen(src) + strlen(dst))
size_t xstrlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
    size_t src_len = strlen(src);
    size_t dst_len = strlen(dst);
    size_t ret = src_len + dst_len;
    if(src_len) {
        /* size_t len = (dstsize > src_len + dst_len) ? src_len + dst_len : dstsize - 1; */
        size_t len = (ret >= dstsize) ? dstsize - 1 : ret;
        memcpy(dst + dst_len, src, len - dst_len);
        dst[len] = '\0';
    }
    return src_len + dst_len;
}

int main(){
  char a[6] = "abc";
  char b[3] = "cd";
  size_t ret = xstrlcat(a, b, 7);
  printf("%s %zu\n", a, ret);
}
