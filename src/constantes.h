#ifndef CONSTANTES_H
#define CONSTANTES_H

#define naoFazNada() ;

//================MACROS
#define LIMPA_BUFFER() scanf("%*[^\n]"); getchar() //forma mais portatil que achei
//#if defined(WIN32) && !defined(UNIX)
#ifdef _WIN32
    //windows
    #define TITULO_JANELA(texto) system("title " #texto)
    #define LIMPA_TELA() system("cls")
    #define PAUSA_TELA() system("pause")
    #define MUDA_COR_DO_PROMPT() system("color 0a")
    #define PAGINA_DE_CODIGO_CHCP(codigo) system("chcp " #codigo " && cls")

//#elif defined(UNIX) && !defined(WIN32)
#elif defined __unix__
    //Linux
    #define TITULO_JANELA(texto) naoFazNada()
    #define LIMPA_TELA() system("clear")
    #define PAUSA_TELA() getchar(); scanf("c\n")
    #define MUDA_COR_DO_PROMPT() naoFazNada()
    #define getche() getchar()
    #define getch() getchar()
    #define PAGINA_DE_CODIGO_CHCP(codigo) naoFazNada()
#else
    //Outro Sistema
    #define TITULO_JANELA(texto) naoFazNada()
    #define LIMPA_TELA() printf("\n\n\n\n\n\n\n\n\n\n\n\n\n")
    #define PAUSA_TELA() getchar(); scanf("c\n")
    #define MUDA_COR_DO_PROMPT() naoFazNada()
    #define getche() getchar()
    #define getch() getchar()
    #define PAGINA_DE_CODIGO_CHCP(codigo) naoFazNada()
#endif

#endif //CONSTANTES_H
