#include <GL/gl.h> 							//biblioteca que permite todas as chamadas da API openGL
#include <GL/glut.h> 						//biblioteca que permite a manipula��o de janelas
#include <Math.h>                  					 //conjunto de fun��es para opera��es matem�ticas

GLint direcao=0;               				// valor que determina o est�gio do loop
GLint movecarrox = 0, movecarroy = 0;     	// vari�veis de movimenta��o para x e y

void timerCarro(int passo){               		 //fun��o timerCarro, que verifica o local do ponto para saber quando deve parar de subir (ou descer) o ponto no eixo y
    switch(direcao){
    case 0:
        movecarrox +=1;
        if (movecarrox == 72){
            direcao = 1;
        }
        break;
    case 1:
        movecarroy +=1;
        if (movecarroy == 72){
            direcao = 2;
        }
        break;
    case 2:
        movecarrox -=1;
        if (movecarrox == 0){
            direcao = 3;
        }
        break;
    case 3:
        movecarroy -=1;
        if (movecarroy == 0){
            direcao = 0;
        }
        break;
    }
    glutPostRedisplay();                 		//chama a fun��o desenha toda vez que for necess�ria
    glutTimerFunc(25,timerCarro,1);      	//precisamos chamar a fun��o timer toda vez, ela executa e retorna a este ponto novamente. At� ser desejada a sa�da da fun��o timer (neste caso, n�o queremos sair)
}

void arvore(float x, float y){                      //Fun��o utilizada para criar �rvores no local informado via refer�ncia
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(3,3,0);
    glBegin(GL_QUADS);
    glColor3f(0.75, 1, 0);                      //Copa da �rvore
        glVertex2f(6.5, 5);
        glVertex2f(6.5, 3);
        glVertex2f(4.5, 3);
        glVertex2f(4.5, 5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(3,3,0);
    glBegin(GL_QUADS);
    glColor3f(0.72, 0.45, 0.2);                  //Tronco da �rvore
        glVertex2f(6, 3);
        glVertex2f(6, 1);
        glVertex2f(5, 1);
        glVertex2f(5, 3);
    glEnd();
    glPopMatrix();
}

void cenario(){
    glBegin(GL_QUADS);
        glColor3f(0.09,0.6,0.145);
        glVertex2f(-50,-50);                        //Fundo verde (Grama)
        glVertex2f(-50,50);
        glVertex2f(50,50);
        glVertex2f(50,-50);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0,0,0);
        glVertex2f(-40,40);
        glVertex2f(40,40);                          //Pista
        glVertex2f(40,-40);
        glVertex2f(-40,-40);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.09,0.6,0.145);
        glVertex2f(-21,-20);                                        //Canteiro interior
        glVertex2f(-21,20);
        glVertex2f(21,20);
        glVertex2f(21,-20);
    glEnd();

    glEnable(GL_LINE_STIPPLE);
    glEnable(GL_LINE_SMOOTH);
        glLineStipple(7, 0x99999);
    glBegin(GL_LINES);                                            //Faixas da pista
    glLineWidth(30.0);
    glColor3f(1, 1, 0.0);
        glVertex2f(-31, -30);
        glVertex2f(-31, 30);
        glVertex2f(31, 30);
        glVertex2f(31, -30);
        glVertex2f(-31, 30);
        glVertex2f(31, 30);
        glVertex2f(-31, -30);
        glVertex2f(31, -30);
    glEnd();
    glEnable(GL_LINE_SMOOTH);
    glDisable(GL_LINE_STIPPLE);

    glBegin(GL_QUADS);
        glColor3f(0.6,0.85,0.917);
        glVertex2f(1,-3);
        glVertex2f(1,15);                                     //Lagoa
        glVertex2f(17,15);
        glVertex2f(17,-3);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.47, 0.26, 0.08);
        glVertex2f(-16, 10);
        glVertex2f(-10, 15);                                   //Telhado da casa
        glVertex2f(-4, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.91, 0.54, 0.11);
        glVertex2f(-5, 10);
        glVertex2f(-5, 0);                                      //Parede da casa
        glVertex2f(-15, 0);
        glVertex2f(-15, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6,0.85,0.917);
        glVertex2f(-10, 7);
        glVertex2f(-14, 7);                                      //Janela da casa
        glVertex2f(-14, 3);
        glVertex2f(-10, 3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.47, 0.26, 0.08);
        glVertex2f(-6, 7);
        glVertex2f(-6, 0);
        glVertex2f(-9, 0);                                  //Porta da casa
        glVertex2f(-9, 7);
    glEnd();

    arvore(-20, -20);
    arvore(-30, -17);
    arvore(-5, -7);
    arvore(-8, -17);
    arvore(0, -22);
    arvore(-18, 4);
}

void carro(){
    if (direcao == 0){
        glBegin(GL_QUADS);
        glColor3f(1,0,0);
        glVertex2f(-38,-35);
        glVertex2f(-38,-39);                      //Carro
        glVertex2f(-32,-39);
        glVertex2f(-32,-35);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0,0,0);
        glVertex2f(-34,-36);
        glVertex2f(-34,-38);          //Janela do carro
        glVertex2f(-33,-38);
        glVertex2f(-33,-36);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0,0,0);
        glVertex2f(-37,-36);
        glVertex2f(-37,-38);                        //Janela do carro
        glVertex2f(-38,-38);
        glVertex2f(-38,-36);
    glEnd();
    }
    if (direcao == 1){
        glBegin(GL_QUADS);
        glColor3f(1,0,0);
        glVertex2f(-35,-38);
        glVertex2f(-39,-38);                      //Carro
        glVertex2f(-39,-32);
        glVertex2f(-35,-32);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0,0,0);
        glVertex2f(-36,-34);
        glVertex2f(-38,-34);          //Janela do carro
        glVertex2f(-38,-33);
        glVertex2f(-36,-33);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0,0,0);
        glVertex2f(-36,-37);
        glVertex2f(-38,-37);                        //Janela do carro
        glVertex2f(-38,-38);
        glVertex2f(-36,-38);
    glEnd();
    }
    if (direcao == 2){
        glBegin(GL_QUADS);
        glColor3f(1,0,0);
        glVertex2f(-38,-35);
        glVertex2f(-38,-39);                      //Carro
        glVertex2f(-32,-39);
        glVertex2f(-32,-35);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0,0,0);
        glVertex2f(-33,-36);
        glVertex2f(-33,-38);          //Janela do carro
        glVertex2f(-32,-38);
        glVertex2f(-32,-36);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0,0,0);
        glVertex2f(-36,-36);
        glVertex2f(-36,-38);                        //Janela do carro
        glVertex2f(-37,-38);
        glVertex2f(-37,-36);
    glEnd();
    }
    if (direcao == 3){
        glBegin(GL_QUADS);
        glColor3f(1,0,0);
        glVertex2f(-35,-38);
        glVertex2f(-39,-38);                      //Carro
        glVertex2f(-39,-32);
        glVertex2f(-35,-32);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0,0,0);
        glVertex2f(-36,-33);
        glVertex2f(-38,-33);          //Janela do carro
        glVertex2f(-38,-32);
        glVertex2f(-36,-32);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0,0,0);
        glVertex2f(-36,-36);
        glVertex2f(-38,-36);                        //Janela do carro
        glVertex2f(-38,-37);
        glVertex2f(-36,-37);
    glEnd();
    }
}


void desenhaObjeto(void){                				 //fun��o de desenho
    glClear(GL_COLOR_BUFFER_BIT);         				//buffer padr�o; limpa a tela toda vez que a fun��o � chamada
	glMatrixMode(GL_PROJECTION);          			//proje��o dos pontos definidos no plano cartesiano
    glLoadIdentity(); 				      			//carrega a proje��o
    gluOrtho2D(-50,50,-50,50);            				//define o tamanho do plano cartesiano
	glMatrixMode(GL_MODELVIEW);           			//proje��o do tipo modelo
    glLoadIdentity();                     					//carrega essa identidade de proje��o de modelo

    glPushMatrix();
        cenario();
    glPopMatrix();

    glPushMatrix();                           					//insere a matriz de transforma��o corrente na pilha
        glTranslatef(movecarrox, movecarroy, 0);
        carro();                  						// chama a fun��o que desenha um quadrado
    glPopMatrix();                           					 //retira a matriz do topo da pilha e torna esta �ltima a matriz de transforma��o corrente

	glFlush();                                				//carrega os comandos OpenGL (envia para o hardware os comandos, permitindo assim que os drivers GL iniciem o render)
}


int main(void){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);                        			// somente um buffer | sistema de cores RGB
    glutInitWindowSize(800,600);                                        					// define o tamanho da janela
     glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,        		 // medidas usadas para posicionar a janela no meio
                           (glutGet(GLUT_SCREEN_HEIGHT)-540)/2);       				 // da tela - isso depende da resolu��o do monitor
	glutCreateWindow("Exemplo - Teclado");                             			 // permite a cria��o de uma janela
    glutDisplayFunc(desenhaObjeto);                                     				// fun��o de callback - chama a fun��o Desenha
    glutTimerFunc(10,timerCarro,1);                                  					// tr�s valores dispon�veis (tempo (milissegundos) a o nome da fun��o e valor padr�o para retorno)
    glClearColor(1,1,1,0);                                              					// informa a cor de fundo da tela
    glutMainLoop();                                                     					// loop infinito - escuta as informa��es do sistema at� encerrar a aplica��o
    return 0;                                                           						// retorna zero
}
