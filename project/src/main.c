#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>

#include "common.h"
#include "parse.h"

void print_usage(char *argv[]) {
	printf("Usage %s -n -f <database file>\n", argv[0]);
	printf("\t -n - create database file\n");
	printf("\t -f - (required) path to databse file\n");
	return;
}



int main(int argc, char *argv[]) {

	char *filepath = NULL;
	bool newfile = false;
	int c;
	while ((c = getopt(argc, argv, "nf:")) != -1) {
		switch(c) {
			case 'n':
				newfile = true;
				break;
			case 'f':
				filepath = optarg;
				break;
			case '?':
				printf("Unknown option %c", c);
				break;
			default:
				return -1;
		}
	}
	if (filepath == NULL) {
		printf("Filepath is a required argument\n");
		print_usage(argv);
		return 0;
	}

	if (newfile) {
		dbfd = create_db_file(filepath);
		if (dfdb == STATUS_ERROR) {
			printf("Unable to create database file\n");
			return -1;
		}
		create_db_header(dbfd, &dbhdr);
	} else {
		dbfd = open_db_file(filepath);
		if (dfdb == STATUS_ERROR) {
			printf("Unable to open database file\n");
			return -1;
		}
	}


	printf("Newfile: %d\n", newfile);
	printf("Filepath: %s\n", filepath);
	return 0;	
}
	
