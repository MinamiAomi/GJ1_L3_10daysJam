#include "MapBlock.h"

#include "Framework/AssetManager.h"

#include "MapProperty.h"
#include "Map.h"

void MapBlock::OnInitialize() {

    transform.SetParent(&map_.transform);
    transform.translate = { 2.0f * (float)column_ - (float)MapProperty::kMapColumn, -2.0f * (float)row_, 0.0f };
    transform.scale = Vector3::one;
    transform.rotate = Quaternion::identity;
    transform.UpdateMatrix();

    model_.SetModel(AssetManager::GetInstance()->FindModel("block"));
    model_.SetWorldMatrix(transform.worldMatrix);

    isActive_ = true;
}

void MapBlock::OnUpdate() {

}

void MapBlock::OnBreak() {

}
