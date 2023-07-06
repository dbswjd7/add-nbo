#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <netinet/in.h>




uint32_t byteorder(char *filename){
	FILE* fp;
	uint32_t tmp;
	
	fp = fopen(filename, "rb");
    	if(fp == NULL) {
        	printf("Failed to open file: %s\n", filename);
       		 return 0;
    	}
    	
    	
    	fread(&tmp, sizeof(uint32_t), 1, fp);    	
    	tmp = htonl(tmp);
    	fclose(fp);
    	return tmp;    	
}

int main(int argc,char *argv[]) {
	if(argc < 3){
		printf("Usage : %s <file1> <file2>\n", argv[0]);
		return 0;
	}
	uint32_t a=byteorder(argv[1]);
	uint32_t b=byteorder(argv[2]);
	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n",a,a,b,b,a+b,a+b);
	return 0;
}
