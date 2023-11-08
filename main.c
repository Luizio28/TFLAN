#include <windows.h>
#include "resources.h"

HBITMAP hBitmap;
HBITMAP hClass;

HWND hwndEditName;
HWND hwndEditIP;
HWND hwndComboQuality;

HWND hwndHelpText;
HWND hwndKit;
HWND hwndInfo;

HWND hwndPlusButton;
HWND hwndMinusButton;
HWND hwndCorSample;

HBRUSH hBrushCorSample;

HWND hwndFullscreenCheckBox;

HWND hwndClassDropdown;
HWND hwndClassLabel;

int telaCheia = 0;
int numeroCor = 1;
int side0 = 275;
int side1 = 12;
int tops = 8;

const char* classImageFiles[] = {
    "_gfx/scout.bmp",
    "_gfx/sniper.bmp",
    "_gfx/soldier.bmp",
    "_gfx/demoman.bmp",
    "_gfx/medic.bmp",
    "_gfx/hwguy.bmp",
    "_gfx/pyro.bmp",
    "_gfx/spy.bmp",
    "_gfx/engineer.bmp"
};

const char* classDescriptions[] = {
    // SCOUT
    "1. Scout (Batedor/Corredor)\r\n"
    "75 HP | 50 AP Armadura Leve\r\n"
    "Tipo: SUPORTE\r\n"
    "*Desarma a bomba do demoman\r\n"
    "*Descobre espiões\r\n"
    "*Detecta bandeira e inimigos",
	// SNIPER
    "2. Sniper (Atirador)\r\n"
    "90 HP | 50 AP Armadura Leve\r\n"
    "Tipo: DEFENSOR\r\n"
    "*Headshot: 3x Dano\r\n"
    "*Tiro na perna: Lentidão\r\n"
    "*Segure o clique para aumentar dano",
	// SOLDIER
    "3. Soldier (Soldado)\r\n"
    "Tipo: ATACANTE\r\n"
    "100 HP | 200 Armadura Pesada\r\n"
    "*Mais versátil\r\n"
    "*Salto-foguete (SHIFT) alcança alturas\r\n",
	// SOLDIER
    "4. DemoMan (Cara das Demolições)\r\n"
    "90 HP | 120 AP Armadura Média\r\n"
    "Tipo: DEFENSOR\r\n"
    "*Detone minas com MOUSE2\r\n"
    "*Bomba abre passagens em grades e bloqueios\r\n",
	// MEDIC
    "5. Medic (Médico de Combate)\r\n"
    "90 HP | 100 AP Armadura Média\r\n"
    "Tipo: ATACANTE\r\n"
    "*Aperte [1]: Modo do Medikit (infectar / curar)\r\n"
    "*Regenera vida",
	// HEAVY
    "6. HWGuy (Armas Pesadas)\r\n"
    "100 HP | 300 AP Armadura Pesada\r\n"
    "Tipo: DEFENSOR\r\n"
    "*Fique parado e tenha baterias (cells) para usar metralhadora\r\n",
	// PYRO
    "7. Pyro (Incendiário)\r\n"
    "100 HP | 150 AP Armadura Média\r\n"
    "Tipo: SUPORTE\r\n"
    "*Armadura imune ao fogo\r\n",
	// SPY
    "8. Spy (Espião)\r\n"
    "100 HP | 90 AP Armadura Média\r\n"
    "Tipo: ATACANTE\r\n"
    "*MOUSE2: Disfarce\r\n"
    "*Movimento é visivel ao fingir morte\r\n",
	// ENGI
    "9. Engineer (Engenheiro)\r\n"
    "80 HP | 50 AP Armadura Média\r\n"
    "Tipo: DEFENSOR\r\n"
    "*Constrói/Melhora Sentinela e Fornecedor de Suprimentos com metal\r\n"
    "*Desarma bomba do DemoMan\r\n"
};

const char* helpText =
"Checar Nome:\tE\r\n"
"Trocar Classe:\tB\r\n"
"Trocar Time:\tM\r\n"
"Armas:\t\t1-7\r\n"
"Ultima Arma:\tQ\r\n"
"Recarregar:\tR\r\n"
"Granadas:\tF / G\r\n"
"Special:\t\tMouse2 / SHIFT\r\n"
;

const char* classKits[] ={
    //scout
    "# ARMAS:\t\t(1) Machado\r\n"
    "(2) Shotgun\t\t(3) -\r\n"
    "(4) Arma de Pregos\t(5) -\r\n"
    "(6) -\t\t\t(7) -\r\n"
    "\r\n"
    "# GRANADAS / SPECIAL:\r\n"
    "(F) Lata de Espinhos\t(G) Grn. de Tonteira\r\n"
    "(MOUSE2) Scanner\t(SHIFT) -\r\n",
    // Sniper
    "# ARMAS:\t\t(1) Machado\r\n"
    "(2) Rifle\t\t\t(3) Auto-Rifle\r\n"
    "(4) Arma de Pregos\t(5) -\r\n"
    "(6) -\t\t\t(7) -\r\n"
    "\r\n"
    "# GRANADAS / SPECIAL:\r\n"
    "(F) Grn. Normal\t\t(G) Tocha\r\n"
    "(MOUSE2) Zoom\t\t(SHIFT) -\r\n",
    // soldier
    "(1) Machado\r\n"
    "(2) Shotgun\t\t(3) Super-Shotgun\r\n"
    "(4) -\t\t\t(5) -\r\n"
    "(6) -\t\t\t(7) Bazuca\r\n"
    "\r\n"
    "(F) Grn. Normal\t\t(G) Grn. de Pregos\r\n"
    "\r\n"
    "(MOUSE2) Bazuca\t(SHIFT) Salto-Foguete\r\n",
    // demoman
    "# ARMAS:\t\t(1) Machado\r\n"
    "(2) Shotgun\t\t(3) -\r\n"
    "(4) -\t\t\t(5) -\r\n"
    "(6) Lança-Granadas\t(7) Lança-Minas\r\n"
    "\r\n"
    "# GRANADAS / SPECIAL:\r\n"
    "(F) Grn. Normal\t\t(G) Grn. Super\r\n"
    "(MOUSE2) Detonar Minas\t(SHIFT) Plantar Bomba\r\n",
    // medic
    "# ARMAS:\t\t(1) Medikit / Arma Biológica\r\n"
    "(2) -\t\t\t(3) Super-Shotgun\r\n"
    "(4) -\t\t\t(5) Super Arma de Pregos\r\n"
    "(6) -\t\t\t(7) -\r\n"
    "\r\n"
    "# GRANADAS / SPECIAL:\r\n"
    "(F) Grn. Normal\t\t(G) Grn. de Tonteira\r\n"
    "(MOUSE2) Medikit \t(SHIFT) -\r\n",
    // hwguy
    "# ARMAS:\t\t(1) Machado\r\n"
    "(2) Shotgun\t\t(3) Super-Shotgun\r\n"
    "(4) -\t\t\t(5) -\r\n"
    "(6) -\t\t\t(7) Metralhadora\r\n"
    "\r\n"
    "# GRANADAS / SPECIAL:\r\n"
    "(F) Grn. Normal\t\t(G) Grn. Normal\r\n"
    "(MOUSE2) Metralhadora\t(SHIFT) -\r\n",
    // pyro
    "# ARMAS:\t\t(1) Machado\r\n"
    "(2) Shotgun\t\t(3) -\r\n"
    "(4) -\t\t\t(5) -\r\n"
    "(6) Lança-Chamas\t(7) Lança-Fogos\r\n"
    "\r\n"
    "# GRANADAS / SPECIAL:\r\n"
    "(F) Lata de Espinhos\t(G) Grn. de Fogo\r\n"
    "(MOUSE2) Lança-Chamas\t(SHIFT) -\r\n",
    // spy
    "# ARMAS:\t\t(1) Faca\r\n"
    "(2) Tranquilizante\t(3) Super-Shotgun\r\n"
    "(4) Arma de Pregos\t(5) -\r\n"
    "(6) -\t\t\t(7) -\r\n"
    "\r\n"
    "# GRANADAS / SPECIAL:\r\n"
    "(F) Grn. Normal\t\t(G) Gas Halucinógeno\r\n"
    "(MOUSE2) Disfarce\t(SHIFT) Fingir Morte\r\n",
    // engi
    "# ARMAS:\t\t(1) Ferramenta\r\n"
    "(2) Canhão Elétrico\t(3) Super-Shotgun\r\n"
    "(4) -\t\t\t(5) -\r\n"
    "(6) -\t\t\t(7) -\r\n"
    "\r\n"
    "# GRANADAS / SPECIAL:\r\n"
    "(F) Grn. Normal\t\t(G) Grn. Elétrica\r\n"
    "(MOUSE2) Construir\t(SHIFT) Criar Munição\r\n"
};
;

const char* classes[] = {
    "1. Scout",
    "2. Sniper",
    "3. Soldier",
    "4. Demoman",
    "5. Medic",
    "6. HWGuy",
    "7. Pyro",
    "8. Spy",
    "9. Engineer"
};

int classIndex = 2;

COLORREF cores[] = {
    RGB(219, 219, 219),   // 0
    RGB(131, 103, 35),     // 1
    RGB(138, 138, 255),   // 2
    RGB(107, 107, 15),       // 3
    RGB(127, 0, 0),       // 4
    RGB(175, 103, 35),     // 5
    RGB(255, 243, 27),     // 6
    RGB(227, 179, 151),   // 7
    RGB(171, 139, 163),  // 8
    RGB(175, 107, 143),     // 9
    RGB(203, 179, 167),   // 10
    RGB(103, 123, 111),   // 11
    RGB(239, 223, 23),     // 12
    RGB(35, 35, 191),   // 13
    RGB(238, 142, 59)      // 14
};

#define ID_MEU_ICONE 101


void ExecutarQuake(const char* nickname, const char* serverIP, const char* qualidadeGrafica) {
    // Montar o comando para executar o "quake.exe" com os parâmetros
    char comando[300];
    sprintf(comando,
        "quake.exe -game fortress +name %s +connect %s +exec video-%s +alias usercolor \"topcolor %d\" +vid_fullscreen %d +alias userclass \"impulse %d\" +alias defteam \"impulse 5\"",
        nickname, serverIP, qualidadeGrafica, numeroCor, telaCheia, classIndex+1);

    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    // Criar o processo em segundo plano
    if (CreateProcess(NULL, comando, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    } else {

    }
}

LRESULT CALLBACK janelaPrincipal(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE:
            // #LADO DIREITO
            hBitmap = (HBITMAP)LoadImage(NULL, "_gfx/title.bmp", IMAGE_BITMAP, 250, 90, LR_LOADFROMFILE);
            if (hBitmap == NULL) {
                MessageBox(hwnd, "Erro ao carregar a imagem.", "Erro", MB_ICONERROR);
            }
            hClass = (HBITMAP)LoadImage(NULL, classImageFiles[classIndex], IMAGE_BITMAP, 120, 90, LR_LOADFROMFILE);
            if (hClass == NULL) {
                MessageBox(hwnd, "Erro ao carregar a imagem da Classe.", "Erro", MB_ICONERROR);
            }
            hwndKit = CreateWindow("Static", classKits[classIndex], WS_CHILD | WS_VISIBLE,
                side0, tops+114, 380, 136, hwnd, NULL, NULL, NULL);
            hwndInfo = CreateWindow("Static", classDescriptions[classIndex], WS_CHILD | WS_VISIBLE,
                side0+120, tops, 238, 110, hwnd, NULL, NULL, NULL);
            // Cria uma caixa de texto não editável para exibir o texto de ajuda com barra de rolagem
            hwndHelpText = CreateWindowEx(WS_EX_CLIENTEDGE, "Edit", "", WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL | ES_READONLY | WS_VSCROLL,
               side0, tops+250, 356, 122, hwnd, (HMENU)5, NULL, NULL);
            // Preenche a caixa de texto com o texto de ajuda
            SetWindowText(hwndHelpText, helpText);

            // #LADO ESQUERDO
            // Cria um label para o nickname
            CreateWindow("Static", "Nome:", WS_CHILD | WS_VISIBLE,
                side1, tops+106, 120, 24, hwnd, NULL, NULL, NULL);
            // Cria um campo de edição de texto para o nickname
            hwndEditName = CreateWindowEx(0, "Edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER,
                side1+120, tops+106, 130, 24, hwnd, (HMENU)1, NULL, NULL);
            // Cria um label para a Cor
            CreateWindow("Static", "Cor Pessoal:", WS_CHILD | WS_VISIBLE,
                side1, tops+130, 120, 24, hwnd, NULL, NULL, NULL);
            // aumentar o número de cor
            hwndMinusButton = CreateWindow("BUTTON", "<-", WS_CHILD | WS_VISIBLE,
                side1+120, tops+130, 40, 24, hwnd, (HMENU)20, NULL, NULL);
            // diminuir o número de cor
            hwndPlusButton = CreateWindow("BUTTON", "->", WS_CHILD | WS_VISIBLE,
                side1+120+90, tops+130, 40, 24, hwnd, (HMENU)21, NULL, NULL);
            // Crie uma área para exibir a amostra de cor
            hwndCorSample = CreateWindow("STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE,
                side1+120+40, tops+130, 50, 24, hwnd, NULL, NULL, NULL);
            hBrushCorSample = CreateSolidBrush(cores[numeroCor]);
            SetBkColor(GetDC(hwndCorSample), cores[numeroCor]);
            // Label Classes
            CreateWindow("Static", "Classe:", WS_CHILD | WS_VISIBLE,
                side1, tops+154, 100, 24, hwnd, NULL, NULL, NULL);
            // Crie o menu drop-down para escolher classes
            hwndClassDropdown = CreateWindowEx(0, "COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | WS_BORDER,
                side1+100, tops+154, 150, 240, hwnd, (HMENU)6, NULL, NULL);
            // Adicione as classes ao menu suspenso
            for (int i = 0; i < 9; i++) {
                SendMessage(hwndClassDropdown, CB_ADDSTRING, 0, (LPARAM)classes[i]);
            }
            SendMessage(hwndClassDropdown, CB_SETCURSEL, classIndex, 0);
            // Cria um label para o IP do servidor
            CreateWindow("Static", "IP do Servidor:", WS_CHILD | WS_VISIBLE,
                side1, tops+200, 120, 24, hwnd, NULL, NULL, NULL);
            // Cria um campo de edição de texto para o IP do servidor
            hwndEditIP = CreateWindowEx(0, "Edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER,
                side1+120, tops+200, 130, 24, hwnd, (HMENU)2, NULL, NULL);
            // Cria um label para a Qualidade Gráfica
            CreateWindow("Static", "Qualidade:", WS_CHILD | WS_VISIBLE,
                side1, tops+224, 120, 24, hwnd, NULL, NULL, NULL);
            // Cria um menu suspenso (dropdown) para a qualidade gráfica
            hwndComboQuality = CreateWindowEx(0, "COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | WS_BORDER,
                side1+120, tops+224, 130, 200, hwnd, (HMENU)3, NULL, NULL);
            SendMessage(hwndComboQuality, CB_SETCURSEL, 1, 0);
            // Adiciona opções ao menu suspenso
            SendMessage(hwndComboQuality, CB_ADDSTRING, 0, (LPARAM)"Rapido");
            SendMessage(hwndComboQuality, CB_ADDSTRING, 0, (LPARAM)"Fiel");
            // Seleciona a primeira opção por padrão
            SendMessage(hwndComboQuality, CB_SETCURSEL, 1, 0);
            // Cria um botão "Executar Quake"
            CreateWindow("Button", "Iniciar TF", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                side1, tops+250, 135, 30, hwnd, (HMENU)4, NULL, NULL);
            // Crie a caixa de seleção para tela cheia com o estilo BS_AUTOCHECKBOX
            hwndFullscreenCheckBox = CreateWindow("BUTTON", "Tela Cheia", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
                side1+150, tops+250, 100, 30, hwnd, (HMENU)40, NULL, NULL);

            // Carregue o ícone a partir dos recursos
            HINSTANCE hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
            HICON hIcon = LoadIcon (hInstance, MAKEINTRESOURCE (IDI_ICON1));
            SendMessage (hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
      return 0;
            break;
        case WM_CTLCOLORSTATIC:
            {
                // Verifique se o controle estático é a área de prévia de cor
                if ((HWND)lParam == hwndCorSample) {
                    // Altere a cor de fundo do controle estático (área de amostra de cor)
                    HDC hdcStatic = (HDC)wParam;
                    SetBkColor(hdcStatic, cores[numeroCor]);
                    return (LRESULT)hBrushCorSample;
                }
                if ((HWND)lParam == hwndHelpText) {
                    HDC hdcStatic = (HDC)wParam;
                    SetBkColor(hdcStatic, RGB(16, 16, 16));  // Define a cor de fundo para branco (ou a cor desejada)
                     SetTextColor(hdcStatic, RGB(200,200,200));
                    return (LRESULT)CreateSolidBrush(RGB(255, 255, 255));  // Cria um pincel branco (ou o pincel com a cor desejada)
                }
            }
            break;
        case WM_COMMAND:
            if (LOWORD(wParam) == 4) {
                // Quando o botão "Executar Quake" é pressionado
                char nickname[100];
                char serverIP[100];
                char qualidadeGrafica[100];

                GetWindowText(hwndEditName, nickname, sizeof(nickname));
                GetWindowText(hwndEditIP, serverIP, sizeof(serverIP));

                // Obtém o índice da opção selecionada no menu suspenso
                int selectedIndex = SendMessage(hwndComboQuality, CB_GETCURSEL, 0, 0);

                // Obtém o texto da opção selecionada
                SendMessage(hwndComboQuality, CB_GETLBTEXT, selectedIndex, (LPARAM)qualidadeGrafica);

                // Executa o "quake.exe" com os parâmetros apropriados
                DestroyWindow(hwnd);
                ExecutarQuake(nickname, serverIP, qualidadeGrafica);

            }
            if (LOWORD(wParam) == 21) {
             // Botão "+" pressionado
                numeroCor = (numeroCor + 1) % 15; // Circula entre 0 e 14
                DeleteObject(hBrushCorSample); // Libere o pincel antigo
                hBrushCorSample = CreateSolidBrush(cores[numeroCor]); // Crie um novo pincel com a nova cor
                InvalidateRect(hwndCorSample, NULL, TRUE); // Redesenhe a área da amostra de cor
            } else if (LOWORD(wParam) == 20) {
             // Botão "-" pressionado
                numeroCor = (numeroCor + 14) % 15; // Circula entre 0 e 14
                DeleteObject(hBrushCorSample); // Libere o pincel antigo
                hBrushCorSample = CreateSolidBrush(cores[numeroCor]); // Crie um novo pincel com a nova cor
                InvalidateRect(hwndCorSample, NULL, TRUE); // Redesenhe a área da amostra de cor
            }
            if (LOWORD(wParam) == 40) {
                // Caixa de seleção foi clicada
                telaCheia = IsDlgButtonChecked(hwnd, 40);
            }
            if (LOWORD(wParam) == 6) {
                // Obtém o índice da classe selecionada no menu drop-down
                classIndex = SendMessage(hwndClassDropdown, CB_GETCURSEL, 0, 0);

                // Verifica se o índice está dentro dos limites válidos
                if (classIndex >= 0 && classIndex < sizeof(classDescriptions) / sizeof(classDescriptions[0])) {
                    // Define o texto da descrição da classe na caixa de texto
                    SetWindowText(hwndKit, classKits[classIndex]);
                    SetWindowText(hwndInfo, classDescriptions[classIndex]);
                    // Define a nova imagem da classe
                    HBITMAP hNewClass = (HBITMAP)LoadImage(NULL, classImageFiles[classIndex], IMAGE_BITMAP, 120, 90, LR_LOADFROMFILE);

                    if (hNewClass != NULL) {
                        // Libere a imagem antiga
                        if (hClass != NULL) {
                            DeleteObject(hClass);
                        }
                        // Atualize a imagem da classe
                        hClass = hNewClass;
                        InvalidateRect(hwnd, NULL, TRUE);
                    }
                }
            }

            break;
        case WM_PAINT:
            {
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(hwnd, &ps);

                // Desenhe a imagem na janela
                if (hBitmap != NULL) {
                    HDC hdcMem = CreateCompatibleDC(hdc);
                    SelectObject(hdcMem, hBitmap);
                    BitBlt(hdc, side1, tops, 250, 90, hdcMem, 0, 0, SRCCOPY);
                    DeleteDC(hdcMem);
                }
                if (hClass != NULL) {
                    HDC hdcMem = CreateCompatibleDC(hdc);
                    SelectObject(hdcMem, hClass);
                    BitBlt(hdc, side0, tops+20, 120, 90, hdcMem, 0, 0, SRCCOPY);
                    DeleteDC(hdcMem);
                }

                EndPaint(hwnd, &ps);
            }
            break;

        case WM_CLOSE:
            // Fecha a janela quando o botão Fechar é pressionado
            DestroyWindow(hwnd);
            if (hBitmap != NULL) {
                DeleteObject(hBitmap);
            }
            if (hClass != NULL) {
                DeleteObject(hClass);
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Cria a janela principal
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, janelaPrincipal, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, "MinhaJanela", NULL };
    RegisterClassEx(&wc);

    HWND hwnd = CreateWindow(wc.lpszClassName, "Team Fortress Lan - by Ranger", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
        100, 100, 640, 420, NULL, NULL, wc.hInstance, NULL);

    // Exibe a janela
    ShowWindow(hwnd, SW_SHOWDEFAULT);
    UpdateWindow(hwnd);

    // Loop de mensagens
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
