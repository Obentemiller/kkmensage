#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <random>


#define RESET "\033[0m"
#define GREEN "\033[32m"  

bool S_DAF;
bool GS_DAF;
bool G_modes = true;
int mytimesleep;
int mytimesending;



////////////////////////////////////////////////////////////////////////////////
static void randowblimp(int ini, int fim, int probabilityOfStar) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(ini, fim);

    for (int i = ini; i <= fim; i++) {
        if (distrib(gen) <= probabilityOfStar) {
            std::cout << "*";
        }
        else {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

static void brightness_transition(int speed) {
    int i = 0;
    while (i != 100) {
        i += speed;
        randowblimp(0, 100, i);
    }

    while (i != 0) {
        i -= speed;
        randowblimp(0, 100, i);
    }
}
////////////////////////////////////////////////////////////////////////////////



static void limparTela() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordScreen = { 0, 0 };
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        return;
    }

    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    if (!FillConsoleOutputCharacter(hConsole, (TCHAR)' ', dwConSize, coordScreen, &cCharsWritten)) {
        return;
    }
    if (!SetConsoleCursorPosition(hConsole, coordScreen)) {
        return;
    }
}


std::string logo = R"(
  _  ___  __                                        
 | |/ / |/ /                                        
 | ' /| ' / _ __ ___   ___ ___ ___  __ _  __ _  ___ 
 |  ; |  ; | '_ ` _ \ / _ \ __/ __|/ _` |/ _` |/ _ \
 | . \| . \| | | | | |  __\__ \__ \ (_| | (_| |  __/
 |_|\_\_|\_\_| |_| |_|\___|___/___/\__,_|\__, |\___|
  github - Obentemiller                   __/ |     
                                         |___/      
)";

std::string logo_h = R"(
  _  ___  __                                         _              _     
 | |/ / |/ /                                        | |            | |    
 | ' /| ' / _ __ ___   ___ ___ ___  __ _  __ _  ___ | |_ ___   ___ | |___ 
 |  ; |  ; | '_ ` _ \ / _ \ __/ __|/ _` |/ _` |/ _ \| __/ _ \ / _ \| / __|
 | . \| . \| | | | | |  __\__ \__ \ (_| | (_| |  __/_ |_ (_) | (_) | \__ \
 |_|\_\_|\_\_| |_| |_|\___|___/___/\__,_|\__, |\___(_)__\___/ \___/|_|___/
  github - Obentemiller                   __/ |                           
                                         |___/                            
)";



std::string ascii_art0 = R"(
    ._________________.       
    |.---------------.|       
    ||               ||       
    ||    PRONTO!    ||        
    ||               ||       
    ||               ||       
    ||_______________||       
    /.-.-.-.-.-.-.-.-.\       
   /.-.-.-.-.-.-.-.-.-.\      
  /.-.-.-.-.-.-.-.-.-.-.\    
 /______/__________\___o_\
 \_______________________/                                                             
)";

std::string ascii_art1 = R"(
    ._________________.       
    |.---------------.|       
    ||               ||       
    ||   ATÉ MAIS!   ||        
    ||  Obentemiller ||       
    ||               ||       
    ||_______________||       
    /.-.-.-.-.-.-.-.-.\     
   /.-.-.-.-.-.-.-.-.-.\    
  /.-.-.-.-.-.-.-.-.-.-.\    
 /______/__________\___o_\
 \_______________________/                                                             
)";

std::string ascii_art2 = R"(
     _________________     
    /                  \      
   /                    \       
  /                      \      
 /_____________obrigado __\     
 |------------------------|
 \________________________/                                                             
)";


static void finalização() {
    Sleep(1000);
    limparTela();
    std::cout << ascii_art0 << std::endl;
    Sleep(1000);
    limparTela();
    std::cout << ascii_art1 << std::endl;
    Sleep(1000);
    limparTela();
    std::cout << ascii_art2 << std::endl;
}


static void renova_interface() {
    limparTela();
    std::cout << logo << std::endl;
}

static void selectgrafic() {
    char in = ' ';
    bool modo = false;

    while (in != 'q') {
        limparTela();
        std::cout << logo << std::endl;
        std::cout << "  <Pressione 'q' para continuar>" << std::endl;
        in = _getch();

        if (in == 'h') {
            in = 'q';
            G_modes = false;
            std::cout << GREEN << "hacking mode" << std::endl;
        }
    }
    brightness_transition(1);


    if (G_modes == true) {
        in = ' ';
        while (in != 'q') {
            limparTela();
            std::cout << logo << std::endl;
            std::cout << "  selecione o modo " << (modo ? "<randow>" : "<message>") << std::endl;
            std::cout << "  <'q' para continuar>" << std::endl;
            in = _getch();
            if (in == 77 || in == 75) {
                modo = !modo;
                S_DAF = modo;
            }
        }
    }
    else if (G_modes == false) {
        in = ' ';
        while (in != 'q') {
            limparTela();
            std::cout << logo_h << std::endl;
            std::cout << "  selecione o modo de ataque " << (modo ? "<modo2>" : "<modo1>") << std::endl;
            std::cout << "  <'q' para continuar>" << std::endl;
            in = _getch();
            if (in == 77 || in == 75) {
                modo = !modo;
                GS_DAF = modo;
            }
        }

    }
    brightness_transition(1);

}

static void press(char tecla) {
    keybd_event(tecla, MapVirtualKey(tecla, 0), 0, 0);
    Sleep(100);
    keybd_event(tecla, MapVirtualKey(tecla, 0), KEYEVENTF_KEYUP, 0);
}


static void toggleCapsLock() {
    INPUT input;
    ZeroMemory(&input, sizeof(INPUT));

    // Pressiona a tecla Caps Lock
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = VK_CAPITAL;
    SendInput(1, &input, sizeof(INPUT));

    // Libera a tecla Caps Lock
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
}



static void stringpress(const std::string& str) {
    for (char c : str) {
        press(c);
    }
}

static void capturarString(std::string& input) {
    printf("<Digite uma string (pressione Enter para encerrar)>: ");
    toggleCapsLock();
    std::getline(std::cin, input);
    toggleCapsLock();
}

static void messagecase() {

    limparTela();

    std::cout << logo << std::endl;

    std::string myString;
    capturarString(myString);

    std::cout << "<quantos " << myString << " deseja enviar?> : ";
    float i_mytimesending;
    std::cin >> i_mytimesending;
    mytimesending = i_mytimesending * 1000;

    std::cout << "<duração até enviar (em segundos)>: ";
    float i_mytimesleep;
    std::cin >> i_mytimesleep;
    mytimesleep = i_mytimesleep * 1000;

    while (i_mytimesleep != 0) {
        i_mytimesleep--;
        renova_interface();
        std::cout << "faltam: " << i_mytimesleep << "s" << std::endl;
        Sleep(1000);
    }

    renova_interface();
    std::cout << "pronto! mandando <" << myString << ">" << std::endl;

    for (mytimesending; mytimesending != 0; mytimesending -= 1000) {
        stringpress(myString);
        press(VK_RETURN);
        renova_interface();
        std::cout << "faltam: " << mytimesending / 1000 << " " << myString << "s para finalizar" << std::endl;
        Sleep(0);
    }
    renova_interface();
    std::cout << "pronto seu babaca!" << std::endl;

    brightness_transition(1);
    limparTela();
    finalização();
}

static void randowcase() {
    limparTela();

    std::cout << logo << std::endl;
    std::cout << "randow_case" << std::endl;


}

static void attack1() {
    limparTela();

    std::cout << logo << std::endl;
    std::cout << "attack1" << std::endl;

}

static void attack2() {
    limparTela();

    std::cout << logo << std::endl;
    std::cout << "attack2" << std::endl;

}

int main() {
    selectgrafic();

    if (G_modes == true) {
        switch (S_DAF) {
        case 0:
            messagecase();
            return 0;
        case 1:
            randowcase();
            return 0;
        }
    }
    else if (G_modes == false) {
        switch (GS_DAF) {
        case 0:
            attack1();
            return 0;
        case 1:
            attack2();
            return 0;
        }
    }

    return 0;
}
