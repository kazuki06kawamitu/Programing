/**********************************************
*�Ԕ����Q�[��������Ă݂悤!
**********************************************/
#include "DxLib.h"
#include "Scene/SceneManager.h"

//���C���֐�(�v���O�����͂�������n�܂�܂��B)
int WINAPI WinMain(_In_HINSTANCE hInstance, _In_opt_HINSTANCE hPrevInstance,
	_In_LPSTR lpCmdLine, _In_int nCmdShow)
{
	//��O����(�ُ킪����������catc���ɔ�т܂�)
	try
	{
		//�V�[���}�l�[�W���[�@�\�̐���
		SceneManager;
		//�V�[���}�l�[�W���[�@�\�̏���������
		manager.Initialize();
		//�V�[���}�l�[�W���[�@�\�̍X�V����
		manager.Update();
		//�V�[���}�l�[�W���[�@�\�̏I��������
		manager.Finalize();
	}
	catch (const char* err_log)
	{
		//�G���[�������e�̏o��
		OutputDebugString(err_log);
		//�G���[�I����ʒm
		return 0;
	}
}