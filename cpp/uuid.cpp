#include <stdio.h>
#include <uuid/uuid.h>
#include <string>

std::string getDeviceId()
{
	char content[256] = {0};
	uuid_t uuid;
	uuid_generate(uuid);
	uuid_unparse_upper(uuid, content);
	return content;
}

int main(int argc, char* argv[])
{
	std::string content(getDeviceId());
	printf("%s\n", content.c_str());
	return 0;
}
