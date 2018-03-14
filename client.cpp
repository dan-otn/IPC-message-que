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



	
	key_t key = ftok("./task1.cpp", 1);
	
	int mkey = msgget(key, IPC_CREAT | 0644);
	
	
	cin >> msg1.op >> msg1.a >> msg1.b;

	msg1.mtype = 1;
	msgsnd(mkey, &msg1, sizeof(msg1)-sizeof(long), 0); 
	
	
		
	msgrcv(mkey, &msg2, sizeof(msg2)-sizeof(long), 2, 0);
	
cout<<"Answer "<<msg2.ans<<endl;
}
