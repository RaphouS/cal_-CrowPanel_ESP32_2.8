# cal_-CrowPanel_ESP32_2.8

Projet de calibration d'écran tactile pour ESP32 avec écran TFT (driver ILI9341) utilisant PlatformIO et la bibliothèque TFT_eSPI.

## Fonctionnalités principales
- Calibration de l'écran tactile avec affichage des coins à toucher
- Affichage graphique sur écran TFT
- Utilisation de la bibliothèque TFT_eSPI optimisée pour ESP32
- Exemples d'utilisation de boutons tactiles (voir code commenté dans `src/main.cpp`)

## Matériel requis
- Carte ESP32 (ex: Denky32)
- Écran TFT compatible ILI9341 (ou autre supporté par TFT_eSPI)
- Écran tactile résistif ou capacitif selon le modèle

## Installation
1. Cloner ce dépôt
2. Installer [PlatformIO](https://platformio.org/)
3. Connecter l'ESP32 et l'écran TFT selon le schéma matériel
4. Modifier le fichier `include/_tft_setup.h` pour adapter la configuration matérielle si besoin
5. Compiler et téléverser avec PlatformIO

## Dépendances
- [TFT_eSPI](https://github.com/Bodmer/TFT_eSPI)
- [TFT_eWidget](https://github.com/Bodmer/TFT_eWidget) (pour les widgets/boutons)

## Structure du projet
- `src/` : Code source principal (`main.cpp`)
- `include/` : Fichiers d'en-tête et configuration écran
- `lib/` : Librairies additionnelles
- `platformio.ini` : Configuration PlatformIO

## Exemple d'utilisation
Le code principal (`src/main.cpp`) réalise la calibration de l'écran tactile et affiche les valeurs à reporter dans la configuration. Un exemple de gestion de boutons tactiles est inclus en commentaire.

## Tests
Des tests unitaires peuvent être ajoutés dans le dossier `test/`.

## Ressources
- [Documentation TFT_eSPI](https://github.com/Bodmer/TFT_eSPI)
- [Documentation PlatformIO](https://docs.platformio.org/)

## Auteur
RaphouS

---
Ce projet est open-source et sous licence MIT.
