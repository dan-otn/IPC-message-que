#include <iostream>
#include <cassert>
#include <cstring>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/msg.h>

using namespace std;

struct msgbuf1{
	long mtype;
	char op;
	float a;
	float b;
};
struct msgbuf2{
	long mtype;
	float ans;
};

int main(int argc, char **argv)
{
	msgbuf1 msg1;
	msgbuf2 msg2;
	msg2.mtype = 2;

	
	key_t key = ftok("./task1.cpp", 1);
	
	int mkey = msgget(key, IPC_CREAT | 0644);
	
	while (true) 
	{
		
		
		msgrcv(mkey, &msg1, sizeof(msg1)-sizeof(long), 1, 0);
 		
	
	float answer;
	if (msg1.op == '+') answer = msg1.a + msg1.b;
	if (msg1.op == '-') answer = msg1.a - msg1.b;
	if (msg1.op == '*' )answer = msg1.a * msg1.b;
	if (msg1.op == '/') answer = msg1.a / msg1.b;
	msg2.ans = answer;
	msgsnd(mkey, &msg2, sizeof(msg2)-sizeof(long), 0); 
	}
}
