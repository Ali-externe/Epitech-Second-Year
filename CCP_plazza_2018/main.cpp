/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** main
*/

#include "reception.hpp"

/*
int incrementCounter(int &counter)
{
    while (counter != 10) {
	std::cout << "Turns : " << counter << std::endl;
	counter++;
    }
    return (counter);
}

int main(void)
{
    std::mutex mtx;
    mtx.lock();
    int i = 0;
    pthread_t t1;
    pthread_t t2;
    mtx.unlock();

    //pthread_create(&t1, NULL, &incrementCounter, NULL);
    t1 = incrementCounter(i);
    t2 = incrementCounter(i);
    std::cout << "Turnst1 : " << t1 << std::endl << "Turnst2 : " << t2 << std::endl;

    return (0);
}*/

int get_command(std::string command)
{
    if (command.compare("status") == 0) {
	std::cout << "Status is : " << "..." << std::endl;
	return (0);
    }
    else if (command.compare("exit") == 0)
	return (2);
    else
	return (3);
    return (0);
}

int check_num(std::string check)
{
    int a = 0;

    for(int i = 0; i != check.length(); i++) {
	if (std::isdigit(check[i]) != 0)
	    a = 1;
	else
	    return 1;
    }
    if (a == 1)
	return 0;
    return (0);
}

int parsing_bis(std::string str, std::string st[])
{
    size_t pos = 0;
    std::string token;
    int space = 0;
    int counter = 0;
    std::string delimiter = " ";

    for (int i = 0; str[i] != '\0'; i++) {
	if (str[i] == ' ')
	    space++;
    }
    std::string tab[space + 1];

    while ((pos = str.find(delimiter)) != std::string::npos) {
	token = str.substr(0, pos);
	tab[counter] = token;
	str.erase(0, pos + delimiter.length());
	counter++;
    }
    return (counter);
}

std::string *parsing(std::string str, std::string st[])
{
    size_t pos = 0;
    std::string token;
    int space = 0;
    int counter = 0;
    std::string delimiter = " ";

    for (int i = 0; str[i] != '\0'; i++) {
	if (str[i] == ' ')
	    space++;
    }
    std::string tab[space + 1];

    while ((pos = str.find(delimiter)) != std::string::npos) {
	token = str.substr(0, pos);
	tab[counter] = token;
	str.erase(0, pos + delimiter.length());
	counter++;
    }
    st = tab;
    return (st);
}

void kitchen(struct s_struct *s_plazza) {
    //if (fork() == 0)
	cooks(s_plazza);
}

void go_to_kitchen(struct s_struct *s_plazza)
{
    std::string pizza = s_plazza->tab[0];
    std::string size = s_plazza->tab[1];
    std::string speed = s_plazza->tab[2];

    std::transform(pizza.begin(), pizza.end(), pizza.begin(), ::tolower);
    std::transform(size.begin(), size.end(), size.begin(), ::tolower);
    std::transform(speed.begin(), speed.end(), speed.begin(), ::tolower);

    if ((check_pizza(pizza, s_plazza) == 0), (check_size(size, s_plazza)) == 0) {
    if (speed.compare(0,1, "x") == 0) {
	if (std::isdigit(speed[1]) != 0)  {
	    std::cout << "You ordered " << speed[1] << " pizza(s)" << std::endl;
	    s_plazza->nb_pizza = speed[1];
		kitchen(s_plazza);
	}
	else
	    std::cout << "That's not a number" << std::endl;
    }
    else
	std::cout << "That's not a number" << std::endl;
    }
}

void printer(std::vector<std::string> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << '\n';
	}
}

std::vector<std::string> splitter(std::string strToSplit)
{
    std::stringstream ss(strToSplit);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, ';')) {
	splittedStrings.push_back(item);
    }
    return splittedStrings;
}

void plazza_func(char **arguments)
{
    int val = 0;
    static int cou = 0;
    std::string command;
    std::stringstream copy;
    std::string sttt[1];
    std::string a_command;
    std::string s_command;
    std::vector<std::string> seg_command;
    struct s_struct *s_plazza = new struct s_struct;

    s_plazza->multiplier = atof(arguments[1]);
    s_plazza->cook_p_k = atoi(arguments[2]);
    s_plazza->time_restock = atoi(arguments[3]);

    std::cout << "plazza > ";
    while (1) {
	    std::getline (std::cin,command);
	    seg_command = splitter(command);
	for (int i = 0; i < seg_command.size(); i++) {
	    command = seg_command.at(i);
	    command.insert(command.end(), ' ');
        if (cou == 0)
            s_command = command;
        cou++;
	    s_plazza->tab = parsing(command, sttt);
	    s_plazza->nb_tab = parsing_bis(command, sttt);
	    if (s_plazza->nb_tab != 3) {
		    val = get_command(s_plazza->tab[0]);
            if (val == 3)
                continue;
            if (val == 2)
                break;
        }
        else {
            if (s_command != command || cou == 1) {
                create_kitchen(s_plazza);
                s_command = command;
            }
		    go_to_kitchen(s_plazza);
        }
    }
    }
}

int main(int argc, char **argv)
{
    if (argc != 4) {
	std::cout << "Error arguments" << std::endl;
	return 84;
    }
    if (check_num(argv[2]) != 0 || check_num(argv[3]) != 0) {
	std::cout << "Error arguments" << std::endl;
	return 84;
    }
    plazza_func(argv);
}
