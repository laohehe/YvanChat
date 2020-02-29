#include "AccountServer.h"

int AccountServer_SignIn(const char * name, const char * password, int sex)
{
	char temp[333];
	cJSON *root = cJSON_CreateObject();
	cJSON *item = cJSON_CreateString("S");
	cJSON_AddItemToObject(root, "type", item);
	item = cJSON_CreateString(name);
	cJSON_AddItemToObject(root, "name", item);
	item = cJSON_CreateString(password);
	cJSON_AddItemToObject(root, "password", item);
	item = cJSON_CreateBool(sex);
	cJSON_AddItemToObject(root, "sex", item);
	char *out = cJSON_Print(root);
	//printf("out :%s\n", out);
	//scanf("%s", temp);


	return 0;
}
