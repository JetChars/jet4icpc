#include <iostream>
using namespace std;


/*==================================================*\
| String Hash
| Notice: mod should be a big enough prime number
|         (bigger than string number)
\*==================================================*/


unsigned int hasha(char *url, int mod){
    unsigned int n = 0;
    char *b = (char *) &n;
    for (int i = 0; url[i]; ++i) b[i % 4] ^= url[i];
    return n % mod;
}

int main(){
    cout<<hasha("helloworld!", 20)<<endl;
}
