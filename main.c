%:include <stdio.h>
%:include <stdlib.h>
%:include <stdbool.h>

typedef struct <%
    double v;
    unsigned i;
%> key;

key max(double *a, unsigned l) <%
    double m = 0;
    unsigned j = 0;
    for(unsigned i = 0; i < l; i++) 
        if(a<:i:> > m) <%
            m = a<:i:>;
            j = i;
        %>
    return (key)<%m, j%>; 
%>

double sum(double *a, unsigned l) <%
    double m = 0;
    for(unsigned i = 0; i < l; i++) 
        m += a<:i:>;
    return m;
%>

bool has(unsigned *a, unsigned l, unsigned t) <%
    for(unsigned i = 0; i < l; i++)
        if(a<:i:> == t) return true;
    return false;
%>

int main() <%
    double Z<:1000:>;
    unsigned G = 0;

    unsigned N = 1;
    double H = 1;
    while(1) <%
        scanf("%u %lf", &N, &H);
        if(!N && !H) break;
        double *a = malloc(sizeof(double) * N);
        unsigned *b = malloc(sizeof(int) * N);
        unsigned c = 0;
        for(unsigned i = 0; i < N; i++) 
            scanf("%lf", a + i);
        double s = sum(a, N);
        if(s == H || !s) Z<:G++:> = 0;
        else if(s < H) Z<:G++:> = -1;
        else <%
            do <%
                if(c >= N) break;
                double pM = 0.0;
                key k;
                if(!c) <%
                    k = max(a, N);
                    b<:c++:> = k.i;
                    a<:k.i:> = k.v - H;
                %>
                for(unsigned l = 0; l < c; l++)
                    pM += a<:b<:l:>:>;
                k = max(a, N);
                b<:c++:> = k.i;
                double m = (k.v + pM) / c;
                for(unsigned l = 0; l < c; l++)
                    a<:b<:l:>:> = m;
            %> while(s - sum(a, N) != H || !has(b, c, max(a, N).i));
            Z<:G++:> = max(a, N).v;    
        %>
        free(a);
        free(b);
    %>
    for(unsigned i = 0; i < G; i++) <%
        if(!Z<:i:>) printf(":D\n");
        else if(Z<:i:> == -1) printf("-.-\n");
        else printf("%.4f\n", Z<:i:>);
    %>
%>