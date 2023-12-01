

class Menu{
public:
    Menu() {}
    void runMenu();

private:
    void printMenu();
    void Menu_Add();
    

    void Menu_SaveToFile();
    void Menu_LoadFromFile();

    void Menu_LoadSavedFile();
    void showSavedFiles();

};