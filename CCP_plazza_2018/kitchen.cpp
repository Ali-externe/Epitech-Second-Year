/*
** EPITECH PROJECT, 2019
** kitchen
** File description:
** kitchen
*/

#include "kitchen.hpp"

Kitchen::Kitchen() {
    this->nb_ingrts = 5;
    this->nb_cooks = 0;
    std::cout << "kitchen creation..." << std::endl;
}

Kitchen::~Kitchen() {

}

void Kitchen::run(struct s_struct *s_plazza)
{
    int speed = 5 ;

    while (1)
    {
        std::this_thread::sleep_for (std::chrono::seconds(speed));
        std::cout << "\nClose Kitchen" << std::endl;
        std::cout << "plazza > ";
        exit(0);
    }
}

void create_kitchen(struct s_struct *s_plazza)
{

    if (fork() == 0) {
        Kitchen kitch;
        std::cout << "Kitchen created." << std::endl;
        kitch.run(s_plazza);
    }
}
  
/*struct mesg_buffer { 
    long mesg_type; 
    char mesg_text[100]; 
} message; 
  
int receive_orders() 
{ 
    key_t key; 
    int msgid; 
  
    // ftok to generate unique key 
    key = ftok("progfile", 65); 
  
    // msgget creates a message queue 
    // and returns identifier 
    msgid = msgget(key, 0666 | IPC_CREAT); 
  
    // msgrcv to receive message 
    msgrcv(msgid, &message, sizeof(message), 1, 0); 
  
    // display the message 
    printf("Data Received is : %s \n",  
                    message.mesg_text); 
  
    // to destroy the message queue 
    msgctl(msgid, IPC_RMID, NULL); 
  
    return 0; 
}*/
