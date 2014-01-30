
typedef struct cutinData {
	int x, y;
	int width, height;
	int orgWidth, orgHeight;
	int alpha;
	int imageFile;
	int state;
	int counter;
	int duration;
}CutinData;

void cutinInit();
void createCutin(int imageFile);
void createCutinWithDuration(int duration, int imageFile);
void createCutinWithDurationAndSize(int duration, int width, int height, int imageFile);
void cutinFunc();
void cutinDraw(void* DBuf);
int isCutinShowing();