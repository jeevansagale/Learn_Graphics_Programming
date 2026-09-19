# Bouncing Ball

So this was to simulate bounciness of a ball. Using some physics concepts.

<video src="Assets/record.mp4" controls width="640"></video>    



## Concepts

### - **Accelaration due to gravity [g]**: 
The constant acceleration gained by an object falling freely toward a massive body.

### - **Coefficient Of Restitution [e]**: 
1. Its the elatiscity of object after collision. Bounciness you can say. 
2. **e = 1** indicates Perfect elatisity, i.e,. no enery is waster after collision.
3. **e = 0** indicates Perfect plastic, i.e,. All enery is used, it stays at bottom.
4. **0 < e < 1** indicates Inelastic, i.e., some enery is lost after collision, like head and sound,etc.
5. **The Standard Formula**
* $$e = \frac{v_f}{v_i}
<br>
* **$v_f$** = Final velocity (speed **after** collision)
* **$v_i$** = Initial velocity (speed **before** collision)


### - **Air Drag [c]**:
1. Friction that acts when a object falls through air is called **Air Drag [Air Resistance]**.
2. The Drag Coefficient $C_{d}$ is a unitless number that measures how aerodynamic an object is.

| $C_{d}$ value | Effect |
|:--:|:--:|
| $\approx$ 0.04 | Most Aerodynamic |
| $\approx$ 0.47 | Moderate Resistance |
| $\approx$ 1.05 | Less Aerodynamic |


## Calculation
We First calculate 

- Force acting on Y-Axis 
<br>

$F_y = mass * g$ 
<br>

- Then we subtract velocity multiplied by air resistance
<br>
$Force_x = Force_x - (ball.velocity_x * c_d)$
<br>
$Force_y = Force_y - (ball.velocity_y * cd)$

- By Newtons Second law :
<br>
$a_y = F_y / m$
<br>
$a_x = F_x / m$

## Controls
| Key  | Function                       |
| :--: | :--:                           |
| P    | Show Debug Screen              |
| R    | Reset Stats                    |
| Esc  | Exit                           |
| Mouse Touch | Teleports the ball there|
