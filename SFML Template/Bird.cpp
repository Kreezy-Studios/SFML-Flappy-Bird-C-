#include "Bird.hpp"

namespace Kreezy {
    Bird::Bird(GameDataRef data) : _data(data) {
	  _curAnim = 0;

	  _animationFrames.push_back(_data->assets.GetTexture("bird01"));
	  _animationFrames.push_back(_data->assets.GetTexture("bird02"));
	  _animationFrames.push_back(_data->assets.GetTexture("bird03"));
	  _animationFrames.push_back(_data->assets.GetTexture("bird04"));

	  _bird.setTexture(_animationFrames.at(_curAnim));
	  _bird.setPosition((SCREEN_WIDTH / 4) - (_bird.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_bird.getGlobalBounds().height / 2));

	  _birdState = BIRD_STATE_STILL;

	  sf::Vector2f origin = sf::Vector2f(_bird.getGlobalBounds().width / 2, _bird.getGlobalBounds().height / 2);

	  _bird.setOrigin(origin);
	  _bird.scale(sf::Vector2f(BIRD_SCALE, BIRD_SCALE));

	  _rotation = 0.0f;
    }

    void Bird::DrawBird() {
	  _data->window.draw(_bird);
    }

    void Bird::Animate(float ft) {
	  if (_clock.getElapsedTime().asSeconds() > (BIRD_ANIMATION_DURATION / _animationFrames.size())) {
		if (_curAnim < (_animationFrames.size() - 1)) {
		    _curAnim++;
		} else {
		    _curAnim = 0;
		}

		_bird.setTexture(_animationFrames.at(_curAnim));
		_clock.restart();
	  }
    }

    void Bird::Update(float dt) {
	  if (_birdState == BIRD_STATE_FALLING) {
		_bird.move(0, BIRD_GRAVITY * dt);
		_rotation += BIRD_ROTATION_SPEED * dt;

		if (_rotation > 25.0f) {
		    _rotation = 25.0f;
		}
	  } else if (_birdState == BIRD_STATE_FLYING) {
		_bird.move(0, -(BIRD_FLYING_SPEED * dt));
		_rotation -= BIRD_ROTATION_SPEED * dt;

		if (_rotation < -25.0f) {
		    _rotation = -25.0f;
		}
	  }

	  _bird.setRotation(_rotation);

	  if (_movementClock.getElapsedTime().asSeconds() > BIRD_FLYING_DURATION) {
		_birdState = BIRD_STATE_FALLING;
		_movementClock.restart();
	  }
    }

    void Bird::Tap() {
	  _movementClock.restart();
	  _birdState = BIRD_STATE_FLYING;
    }

    const sf::Sprite &Bird::GetSprite() const {
	  return _bird;
    }
}