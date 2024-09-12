#pragma once

#include <memory>

#include "GameObject/GameObject.h"
#include "Math/Camera.h"
#include "Player.h"

class FollowCamera {
public:
	void Initialize();
	void Update();

	void Reset();

	void SetPlayer(std::shared_ptr<Player> player) { player_ = player; }

	std::shared_ptr<Camera> GetCamera() { return camera_; }
	void SetCamera(std::shared_ptr<Camera> camera) { camera_ = camera; }
	Transform transform_;
private:
	void Debug();
	Vector3 offset_;
	std::shared_ptr<Player> player_;
	std::shared_ptr<Camera> camera_;
};