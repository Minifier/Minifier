# Test unitaire de compression

## Test pour la compression d'image

### Test pour la compression du format JPG

<table>
	<tr>
		<td style="display: flex;flex-flow: column;">
			<h3>Avant la compression:</h3>
			<img src="jpg_test.jpg" width="400" />
			<p><b>Fichier: </b>jpg_test.jpg</p>
			<p><b>Taille: </b>4 524 Ko</p>
		</td>
		<td style="display: flex;flex-flow: column;">
			<h3>Après la compression:</h3>
			<img src="jpg_result.jpg" width="400" />
			<p><b>Fichier: </b>jpg_result.jpg</p>
			<p><b>Taille: </b>349 Ko</p>
		</td>
	</tr>
</table>

```
La taille final représente ici 7.7% de la taille original avec un taux de compression de 70%.
```

### Test pour la compression du format PNG

<table>
	<tr>
		<td style="display: flex;flex-flow: column;">
			<h3>Avant la compression:</h3>
			<img src="png_test.png" width="400" />
			<p><b>Fichier: </b>png_test.png</p>
			<p><b>Taille: </b>8 215 Ko</p>
		</td>
		<td style="display: flex;flex-flow: column;">
			<h3>Après la compression:</h3>
			<img src="png_result.jpg" width="400" />
			<p><b>Fichier: </b>png_result.jpg</p>
			<p><b>Taille: </b>422 Ko</p>
		</td>
	</tr>
</table>

```
La taille final représente ici 5.13% de la taille original avec un taux de compression de 70%.
```

### Test pour la compression du format BMP

<table>
	<tr>
		<td style="display: flex;flex-flow: column;">
			<h3>Avant la compression:</h3>
			<img src="bmp_test.bmp" width="400" />
			<p><b>Fichier: </b>bmp_test.bmp</p>
			<p><b>Taille: </b>4 165 Ko</p>
		</td>
		<td style="display: flex;flex-flow: column;">
			<h3>Après la compression:</h3>
			<img src="bmp_result.jpg" width="400" />
			<p><b>Fichier: </b>bmp_result.jpg</p>
			<p><b>Taille: </b>173 Ko</p>
		</td>
	</tr>
</table>

```
La taille final représente ici 4.15% de la taille original avec un taux de compression de 70%.
```

### Test pour la compression du format GIF

<table>
	<tr>
		<td style="display: flex;flex-flow: column;">
			<h3>Avant la compression:</h3>
			<img src="gif_test.gif" width="400" />
			<p><b>Fichier: </b>gif_test.gif</p>
			<p><b>Taille: </b>753 Ko</p>
		</td>
		<td style="display: flex;flex-flow: column;">
			<h3>Après la compression:</h3>
			<img src="gif_result.jpg" width="400" />
			<p><b>Fichier: </b>gif_result.jpg</p>
			<p><b>Taille: </b>245 Ko</p>
		</td>
	</tr>
</table>

```
La taille final représente ici 33.73% de la taille original avec un taux de compression de 70%.
```

### Test pour la compression du format ICO

<table>
	<tr>
		<td style="display: flex;flex-flow: column;">
			<h3>Avant la compression:</h3>
			<img src="ico_test.ico" width="400" />
			<p><b>Fichier: </b>ico_test.ico</p>
			<p><b>Taille: </b>244 Ko</p>
		</td>
		<td style="display: flex;flex-flow: column;">
			<h3>Après la compression:</h3>
			<img src="ico_result.jpg" width="400" />
			<p><b>Fichier: </b>ico_result.jpg</p>
			<p><b>Taille: </b>11 Ko</p>
		</td>
	</tr>
</table>

```
La taille final représente ici 4.50% de la taille original avec un taux de compression de 70%.
```

### Faire vos propres test

Pour faire vos propres test, voici une liste de lien vers des banques d'images de test.

- png:  http://www.fileformat.info/format/png/sample/index.htm
- bmp:  http://www.fileformat.info/format/bmp/sample/index.htm
- tiff: http://www.fileformat.info/format/tiff/sample/
- psd:  https://www.freepik.com/free-psd
- raw:  http://www.red.com/sample-r3d-files
- gif:  http://www.fileformat.info/format/gif/sample/index.htm
- ico:  http://www.iconarchive.com/tag/ico-files
