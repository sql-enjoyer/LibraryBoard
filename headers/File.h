#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sqlite3.h>
#include "Format.h"
using namespace std;

class File{
private:
	string path;
	string sql;
	char *zErrMsg = 0;
   	int rc;
public:
	File(string path){
		this->path = path;
	};
	static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	   int i;
	   for(i = 0; i<argc; i++) {
	      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	   }
	   printf("\n");
	   // cout << argc << " " << *argv << " " << *azColName << endl;
	   return 0;
	}

	void read(char a, char b){
		sqlite3 *db;

		sql = "SELECT * FROM Books;";
	    sqlite3_open("data.db", &db);
	    rc = sqlite3_exec(db, sql.c_str(), callback, NULL, &zErrMsg);

		if( rc != SQLITE_OK ){
	      fprintf(stderr, "SQL error: %s\n", zErrMsg);
	      sqlite3_free(zErrMsg);
	   	}

	    sqlite3_close(db);
	}
};
