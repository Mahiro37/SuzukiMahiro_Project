#ifndef _STATE_PLAYER_NOT_MOVE_H_
#define _STATE_PLAYER_NOT_MOVE_H_
//=====================================================================
//
// �W�����v��ԊǗ��N���X [state_player_not_move.h]
// Author : Konishi Yuuto
//
//=====================================================================

//=====================================================================
// �C���N���[�h�t�@�C��
//=====================================================================
#include "state_player.h"

//=====================================================================
// �N���X��`
//=====================================================================
class CPlayerStateNotMove : public CPlayerState
{
public:
    CPlayerStateNotMove();     // �R���X�g���N�^
    ~CPlayerStateNotMove();    // �f�X�g���N�^

    static CPlayerStateNotMove* Create();  // �C���X�^���X����
    void Init();                           // ����������
    void Update()override;                 // �X�V����

private:
};
#endif