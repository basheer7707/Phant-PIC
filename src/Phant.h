/**
 *
 * Author: Mohamed Basheer
 *
 * 
 * Licensed under the GPL v3 license.
 *
 */

#ifndef Phant_h
#define Phant_h

#ifdef	__cplusplus
extern "C" {
#endif


    void Phant_Init(char* host, char* publicKey, char* privateKey);
    void Phant_add(char* field, char* data);

    char* Phant_queryString();
    char* Phant_url();
    char* Phant_get();
    char* Phant_post();
    char* Phant_clear();
    char* ToString(void* data, int type);


#ifdef	__cplusplus
}
#endif

#endif	/* Phant_h */
