
typedef struct cutinData {
	int x, y;
	int width, height;
	int alpha;
	int imageFile;
	int state;
	int counter;
}CutinData;

void cutinInit();
void createCutin(int imageFile);
void cutinFunc();
int isCutinShowing();