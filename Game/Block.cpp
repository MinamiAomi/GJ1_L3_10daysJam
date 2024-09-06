#include "Block.h"

#include "Framework/AssetManager.h"
#include "CollisionAttribute.h"
#include "Game/GameProperty.h"

void Block::Initialize(const Vector3& position) {
	SetName("Block");
	model_.SetModel(AssetManager::GetInstance()->FindModel("block"));
	collider_ = std::make_shared<BoxCollider>();
	collider_->SetGameObject(this->shared_from_this());
	collider_->SetCallback([this](const CollisionInfo& collisionInfo) { OnCollision(collisionInfo); });
	collider_->SetCollisionAttribute(CollisionAttribute::Block);
	collider_->SetCollisionMask(CollisionAttribute::Player | CollisionAttribute::PlayerBullet | CollisionAttribute::Enemy);
	collider_->SetIsActive(true);

	transform.translate = position;
	isOnce_ = false;
	isAlive_ = true;
	UpdateTransform();
}

void Block::Update() {

	transform.translate += velocity_;

	// 落下リミット
	if (transform.translate.y <= -GameProperty::GameStageSize.y) {
		transform.translate.y = GameProperty::GameStageSize.y;
		isOnce_ = true;
	}
	// 上から降ってくる
	if (isOnce_ && transform.translate.y <= 0.0f) {
		velocity_ = Vector3::zero;
		transform.translate.y = 0.0f;
		isOnce_ = false;
	}
	UpdateTransform();
}

void Block::OnCollision(const CollisionInfo& info) {
	if (info.gameObject->GetName() == "Bullet") {
 		velocity_ = { 0.0f,-0.3f,0.0f };
	}
	if (info.gameObject->GetName() == "Enemy") {
		isAlive_ = false;
	}
}

void Block::UpdateTransform() {
	transform.UpdateMatrix();
	collider_->SetSize({ 2.0f,2.0f,2.0f });
	collider_->SetCenter(transform.worldMatrix.GetTranslate());
	collider_->SetOrientation(transform.worldMatrix.GetRotate());
	model_.SetWorldMatrix(transform.worldMatrix);
}