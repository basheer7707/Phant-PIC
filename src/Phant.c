/**
 *
 * Author: Mohamed basheer
 *
 * 
 * Licensed under the GPL v3 license.
 *
 */




#include "Phant.h"
#include "string.h"
#include "stdio.h"

#define INT 1
#define CHAR 0
#define FLOAT 2
 
 
//static const char HEADER_POST_URL1[] PROGMEM = "POST /input/";
//static const char HEADER_POST_URL2[] PROGMEM = ".txt HTTP/1.1\n";
//static const char HEADER_PHANT_PRV_KEY[] PROGMEM = "Phant-Private-Key: ";
//static const char HEADER_CONNECTION_CLOSE[] PROGMEM = "Connection: close\n";
//static const char HEADER_CONTENT_TYPE[] PROGMEM = "Content-Type: application/x-www-form-urlencoded\n";
//static const char HEADER_CONTENT_LENGTH[] PROGMEM = "Content-Length: ";
char* _host, _pub, _prv, _params;

void Phant_Init(char* host, char* publicKey, char* privateKey) {
  _host = host;
  _pub = publicKey;
  _prv = privateKey;
  _params = "";
}

void Phant_add(char* field, char* data) {

    //_params += "&" + field + "=" + data;

    strcat(_params,"&");
    strcat(_params,field);
    strcat(_params,"=");
    strcat(_params,data);
}



char* Phant_queryString() {
  return _params;
}

char* Phant_url() {

  char* result = "http://" ;
  strcat(result,_host);
  strcat(result,"/input/");
  strcat(result,_pub);
  strcat(result,".txt");

  strcat(result,"?prvate_key");
  strcat(result,_prv);
  strcat(result,_params);
 
  _params = "";

  return result;

}

char* Phant_get() {

//  String result = "GET /output/" + _pub + ".csv HTTP/1.1\n";
//  result += "Host: " + _host + "\n";
//  result += "Connection: close\n";

  char* result = "GET /output/";
  strcat(result,_pub);
  strcat(result, ".csv HTTP/1.1\n");
  strcat(result, "Host: ");
  strcat(result, _host);
  strcat(result, "\n");
  strcat(result, "Connection: close\n");

  return result;

}

char* Phant_post() {
    char* result;

//  String params = _params.substring(1);
//  String result;
//  //String result = "POST /input/" + _pub + ".txt HTTP/1.1\n";
//  for (int i=0; i<strlen(HEADER_POST_URL1); i++)
//  {
//    result += (char)pgm_read_byte_near(HEADER_POST_URL1 + i);
//  }
//  result += _pub;
//  for (int i=0; i<strlen(HEADER_POST_URL2); i++)
//  {
//    result += (char)pgm_read_byte_near(HEADER_POST_URL2 + i);
//  }
//  result += "Host: " + _host + "\n";
//  //result += "Phant-Private-Key: " + _prv + "\n";
//  for (int i=0; i<strlen(HEADER_PHANT_PRV_KEY); i++)
//  {
//    result += (char)pgm_read_byte_near(HEADER_PHANT_PRV_KEY + i);
//  }
//  result += _prv + '\n';
//  //result += "Connection: close\n";
//  for (int i=0; i<strlen(HEADER_CONNECTION_CLOSE); i++)
//  {
//    result += (char)pgm_read_byte_near(HEADER_CONNECTION_CLOSE + i);
//  }
//  //result += "Content-Type: application/x-www-form-urlencoded\n";
//  for (int i=0; i<strlen(HEADER_CONTENT_TYPE); i++)
//  {
//    result += (char)pgm_read_byte_near(HEADER_CONTENT_TYPE + i);
//  }
//  //result += "Content-Length: " + String(params.length()) + "\n\n";
//  for (int i=0; i<strlen(HEADER_CONTENT_LENGTH); i++)
//  {
//    result += (char)pgm_read_byte_near(HEADER_CONTENT_LENGTH + i);
//  }
//  result += String(params.length()) + "\n\n";
//  result += params;

  _params = "";
  return result;

}

char* Phant_clear() {

//  String result = "DELETE /input/" + _pub + ".txt HTTP/1.1\n";
//  result += "Host: " + _host + "\n";
//  result += "Phant-Private-Key: " + _prv + "\n";
//  result += "Connection: close\n";

  char* result = "DELETE /input/";
  strcat(result, _pub);
  strcat(result, ".txt HTTP/1.1\n");

  strcat(result, "Host: ");
  strcat(result, _host);
  strcat(result, "\n");

  strcat(result, "Phant-Private-Key: ");
  strcat(result, _prv);
  strcat(result, "\n");

  strcat(result, "Connection: close\n");

  
  return result;
}

char* ToString(void* data, int type){
    char* str;
    if (type==INT) //INT conversion
    {
        sprintf(str, "%d", (int*)data);
    }
    else if (type==CHAR) //char conversion
    {
        sprintf(str, "%u", (char*)data);
    }
    else if (type==FLOAT) //float conversion
    {
        sprintf(str, "%f", (float*) data);
    }

    return str;
}