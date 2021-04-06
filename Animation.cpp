#include "Animation.h"

void Animation::bindFrames(Texture tFrames[], int length) {		//�����������飬���鳤��
	frames = new Texture[length];								//�����õ������������
	for (int i = 0; i < length; i++) {							//����̬���峤��
		frames[i] = tFrames[i];
	}
	frameLength = length;
}
void Animation::play() {
	setTexture(frames[frameNo]);			//�趨��ǰ֡������
	frameNo += 1;							//��һ֡
	if (frameNo == frameLength) {			//���¿�ʼ����
		frameNo = 0;
	}
}