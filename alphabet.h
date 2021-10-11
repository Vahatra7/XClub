
void cc(int kk)
{
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    if (kk==0)
    SetConsoleTextAttribute(hConsole,1);
    else
        SetConsoleTextAttribute(hConsole,kk);
}
void A(int ii,int xx)
{
    cc(xx);
    if (ii==1) std::cout << " \4\4\4  "  ;
    if (ii==2) std::cout << "\4   \4 "   ;
    if (ii==3) std::cout << "\4\4\4\4\4 "   ;
    if (ii==4) std::cout << "\4   \4 "   ;
    if (ii==5) std::cout << "\4   \4 "   ;
}

void B(int ii,int xx)
{
    cc(xx);
    if (ii==1) std::cout << "\4\4\4\4  " ;
    if (ii==2) std::cout << "\4   \4 "   ;
    if (ii==3) std::cout << "\4\4\4\4  " ;
    if (ii==4) std::cout << "\4   \4 "   ;
    if (ii==5) std::cout << "\4\4\4\4  " ;

}

void C(int ii,int xx)
{
    cc(xx);
    if (ii==1) std::cout << " \4\4\4\4 " ;
    if (ii==2) std::cout << "\4     "    ;
    if (ii==3) std::cout << "\4     "    ;
    if (ii==4) std::cout << "\4     "    ;
    if (ii==5) std::cout << " \4\4\4\4 " ;

}

void H(int ii,int xx)
{
    cc(xx);
    if (ii==1) std::cout << "\4   \4 "    ;
    if (ii==2) std::cout << "\4   \4 "    ;
    if (ii==3) std::cout << "\4\4\4\4\4 " ;
    if (ii==4) std::cout << "\4   \4 "    ;
    if (ii==5) std::cout << "\4   \4 "    ;
}

void K(int ii,int xx)
{
    cc(xx);
    if (ii==1) std::cout << "\4   \4 " ;
    if (ii==2) std::cout << "\4  \4  "  ;
    if (ii==3) std::cout << "\4\4\4   " ;
    if (ii==4) std::cout << "\4  \4  "  ;
    if (ii==5) std::cout << "\4   \4 " ;
}

void L(int ii,int xx)
{
    cc(xx);
    if (ii==1) std::cout << "\4     "     ;
    if (ii==2) std::cout << "\4     "     ;
    if (ii==3) std::cout << "\4     "     ;
    if (ii==4) std::cout << "\4     "     ;
    if (ii==5) std::cout << "\4\4\4\4\4 " ;
}

void N(int ii,int xx)
{
    cc(xx);
    if (ii==1) std::cout << "\4   \4 "   ;
    if (ii==2) std::cout << "\4\4  \4 "  ;
    if (ii==3) std::cout << "\4 \4 \4 "  ;
    if (ii==4) std::cout << "\4  \4\4 "  ;
    if (ii==5) std::cout << "\4   \4 "   ;
}

void S(int ii,int xx)
{
    cc(xx);
    if (ii==1) std::cout << "\4\4\4\4\4 " ;
    if (ii==2) std::cout << "\4     "     ;
    if (ii==3) std::cout << "\4\4\4\4\4 " ;
    if (ii==4) std::cout << "    \4 "     ;
    if (ii==5) std::cout << "\4\4\4\4\4 " ;
}

void T(int ii,int xx)
{
    cc(xx);
    if (ii==1) std::cout << "\4\4\4\4\4 " ;
    if (ii==2) std::cout << "  \4   "   ;
    if (ii==3) std::cout << "  \4   "   ;
    if (ii==4) std::cout << "  \4   "   ;
    if (ii==5) std::cout << "  \4   " ;
}

void U(int ii,int xx)
{
    cc(xx);
    if (ii==1) std::cout << "\4   \4 "  ;
    if (ii==2) std::cout << "\4   \4 "  ;
    if (ii==3) std::cout << "\4   \4 "  ;
    if (ii==4) std::cout << "\4   \4 "  ;
    if (ii==5) std::cout << " \4\4\4  " ;
}

void X(int ii,int xx)
{
    cc(xx);
    if (ii==1) std::cout << "\4   \4 "  ;
    if (ii==2) std::cout << " \4 \4  "  ;
    if (ii==3) std::cout << "  \4   "   ;
    if (ii==4) std::cout << " \4 \4  "  ;
    if (ii==5) std::cout << "\4   \4 "  ;
}

void fin(int ii)
{
    if (ii==1) std::cout << "\n"   ;
    if (ii==2) std::cout << "\n"   ;
    if (ii==3) std::cout << "\n"   ;
    if (ii==4) std::cout << "\n"   ;
    if (ii==5) std::cout << "\n" ;
}
