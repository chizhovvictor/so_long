<p align="center">
	<img src="Screen Shot 2023-08-03 at 7.50.27 PM.png">
</p>

<h1 align="center">
	Description
</h1>
<p align="center">
	This is a 42 School's project. The project consists in creating a little 2D game with the MiniLibX, the school's graphic library.
</p>

<h2 align="center">
	The Game
</h2>
<p align="center">
	The purpose of the game is to obtain all collectibles of the level and go to finish.
</p>

<h2 align="center">
	Commands
</h2>
<table>
	<tr>
		<td align="center"><code>W</code><br>Moving up</td>
		<td align="center"><code>A</code><br>Moving left</td>
		<td align="center"><code>S</code><br>Moving down</td>
		<td align="center"><code>D</code><br>Moving right</td>
		<td align="center"><code>ESC</code><br>Close the game</td>
	</tr>
</table>

<h2 align="center">
	Running Game
</h2>

```bash
./so_long [MAP.ber]
```

<p align="center">
	A map set is provided.
</p>

<h2 align="center">
	Map Composition
</h2>
<table align="center">
	<tr>
		<td>
			<h3 align="center">
				Valid Characters
			</h3>
			<table align="center">
				<tr>
					<td align="center">Character</td><td align="center">Element</td>
				</tr>
				<tr>
					<td align="center"><code>0</code></td><td align="center">Grass</td>
				</tr>
				<tr>
					<td align="center"><code>1</code></td><td align="center">Wall</td>
				</tr>
				<tr>
					<td align="center"><code>C</code></td><td align="center">Collectible</td>
				</tr>
				<tr>
					<td align="center"><code>E</code></td><td align="center">Exit Door</td>
				</tr>
				<tr>
					<td align="center"><code>P</code></td><td align="center">Starting Position</td>
				</tr>
			</table>
		</td>
		<td>
			<table align="center">
				<h3>
					Map Example
				</h3>
				<tr>
					<td><br><br>
						<pre align="center">
1111111111111
10010000000C1
10000111110C1
1P0011E000001
1111111111111</pre><br><br>
						<p align="center">
							<i>Content .ber file</i>
						</p>
					</td>
					<td>
						<img src="Screen Shot 2023-08-03 at 7.50.27 PM.png"  width="32%">
						<p>
							<i>Render in game</i>
						</p>
					</td>
				</tr>
			</table>
		</td>
	</tr>
</table>

<p>
	To be valid, a map must meet the following conditions :
	<ul>
		<li>be rectangular</li>
		<li>surrounded by walls</li>
		<li>contain only one starting position</li>
		<li>contain only one exit door</li>
		<li>contain at least one collectible</li>
		<li>be composed by only valid characters</li>
		<li>the file contain map must be at .ber format</li>
	</ul>
</p>
<p>
	By respecting the above conditions, you can create your own maps !
</p>
