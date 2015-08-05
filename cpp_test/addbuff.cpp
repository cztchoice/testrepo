#include<iostream>
using namespace std;
/*
** Compute an initial seed as random as possible. In ANSI, rely on
** Address Space Layout Randomization (if present) to increase
** randomness..
*/
#define addbuff(b,p,e) \
  { size_t t = (size_t(e)); \
    memcpy(buff + p, &t, sizeof(t)); p += sizeof(t); }

/* static unsigned int makeseed () { */
/*   char buff[4 * sizeof(size_t)]; */
/*   int p = 0; */
/*   addbuff(buff, p, L);  #<{(| heap variable |)}># */
/*   addbuff(buff, p, &h);  #<{(| local variable |)}># */
/*   addbuff(buff, p, luaO_nilobject);  #<{(| global variable |)}># */
/*   addbuff(buff, p, &lua_newstate);  #<{(| public function |)}># */
/*   for(int i=0; i < 4; i++){ */
/*     printf("%c ", buff); */
/*   } */
/* } */

struct temp{
  int a;
  int b;
  int c;
}t;

int func(int a){
  return 1;
}


int main(){
  int a = 10;
  int *b = new int(10);

  char buff[4 * sizeof(size_t)];
  cout<<sizeof(size_t)<<endl;
  int p = 0;
  addbuff(buff,p,a);
  addbuff(buff,p,b);
  addbuff(buff,p,&t);
  addbuff(buff,p,&func);


  // for(int i=0; i < sizeof(buff); i++){
  //   cout<<buff[i]<<endl;
  // }
  delete b;
}
