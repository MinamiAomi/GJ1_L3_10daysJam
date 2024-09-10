#pragma once
#include "Scene/BaseScene.h"

#include <memory>

#include "Math/Camera.h"
#include "Math/Transform.h"
#include "Math/Random.h"
#include "Graphics/Model.h"
#include "Graphics/LightManager.h"
#include "Audio/AudioSource.h"
#include "Graphics/Skeleton.h"

#include "Game/BulletManager.h"
#include "Game/BlockManager.h"
#include "Game/EnemyManager.h"
#include "Game/Player.h"
#include "Game/Map.h"
#include "Game/FollowCamera.h"
#include "Game/BlockParticles.h"

class GameScene :
    public BaseScene {
public:

    void OnInitialize() override;
    void OnUpdate() override;
    void OnFinalize() override;

private:
    std::shared_ptr<Camera> camera_;
    Vector3 euler_;
    std::shared_ptr<DirectionalLight> sunLight_;

    std::shared_ptr<BulletManager> bulletManager_;
    std::shared_ptr<BlockManager> blockManager_;
    std::shared_ptr<EnemyManager> enemyManager_;
    std::shared_ptr<FollowCamera> followCamera_;
    std::shared_ptr<Player> player_;
    std::shared_ptr<BlockParticles> blockParticles_;

    
    std::shared_ptr<Map> map_;

};
