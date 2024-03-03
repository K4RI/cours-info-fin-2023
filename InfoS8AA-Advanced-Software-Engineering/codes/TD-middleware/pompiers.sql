-- phpMyAdmin SQL Dump
-- version 4.9.5deb2
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost:3306
-- Généré le : lun. 11 jan. 2021 à 23:15
-- Version du serveur :  8.0.22-0ubuntu0.20.04.3
-- Version de PHP : 7.4.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `Pompiers`
--

-- --------------------------------------------------------

--
-- Structure de la table `Appartient`
--

CREATE TABLE `Appartient` (
  `Matricule` varchar(10) NOT NULL,
  `idEq` int NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `Appartient`
--

INSERT INTO `Appartient` (`Matricule`, `idEq`) VALUES
('JS001', 1),
('OB001', 1),
('PE001', 1),
('MJ001', 2),
('SE001', 2),
('TT001', 2),
('JB001', 3),
('JC001', 3),
('PD001', 3),
('JS001', 4),
('PE001', 4),
('VT001', 4),
('CH001', 5),
('MJ001', 5),
('TG001', 5),
('JB001', 6),
('PD001', 6),
('TT001', 6),
('JC001', 7),
('JS001', 7),
('OB001', 7),
('CH001', 8),
('MJ001', 8),
('PE001', 8),
('PD001', 9),
('TT001', 9),
('VT001', 9),
('JS001', 10),
('SE001', 10),
('TG001', 10);

-- --------------------------------------------------------

--
-- Structure de la table `Equipe`
--

CREATE TABLE `Equipe` (
  `idEq` int NOT NULL,
  `DHdebEq` datetime DEFAULT NULL,
  `DHfinEq` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `Equipe`
--

INSERT INTO `Equipe` (`idEq`, `DHdebEq`, `DHfinEq`) VALUES
(1, '2020-11-29 14:00:00', '2020-11-29 22:00:00'),
(2, '2020-11-29 22:00:00', '2020-11-30 06:00:00'),
(3, '2020-11-30 06:00:00', '2020-11-30 14:00:00'),
(4, '2020-11-30 14:00:00', '2020-11-30 22:00:00'),
(5, '2020-11-30 22:00:00', '2020-12-01 06:00:00'),
(6, '2020-12-01 06:00:00', '2020-12-01 14:00:00'),
(7, '2020-12-01 14:00:00', '2020-12-01 22:00:00'),
(8, '2020-12-01 22:00:00', '2020-12-02 06:00:00'),
(9, '2020-12-02 06:00:00', '2020-12-02 14:00:00'),
(10, '2020-12-02 14:00:00', '2020-12-02 22:00:00');

-- --------------------------------------------------------

--
-- Structure de la table `Intervention`
--

CREATE TABLE `Intervention` (
  `idInt` int NOT NULL,
  `DHdebInt` datetime DEFAULT NULL,
  `DHfinInt` datetime DEFAULT NULL,
  `Catégorie` varchar(50) DEFAULT NULL,
  `Ville` varchar(30) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `Intervention`
--

INSERT INTO `Intervention` (`idInt`, `DHdebInt`, `DHfinInt`, `Catégorie`, `Ville`) VALUES
(1, '2020-11-29 15:53:00', '2020-11-29 19:07:00', 'SUAP', 'Nancy'),
(2, '2020-11-29 21:12:00', '2020-11-29 23:35:00', 'accidents de la circulation', 'Laxou'),
(3, '2020-11-30 01:44:00', '2020-11-30 08:06:00', 'incendies', 'Nancy'),
(4, '2020-11-30 10:12:00', '2020-11-30 11:57:00', 'risques technologiques', 'Nancy'),
(5, '2020-11-30 19:37:00', '2020-12-01 02:43:00', 'incendies', 'Laxou'),
(6, '2020-12-01 04:03:00', '2020-12-01 06:15:00', 'opérations diverses', 'Nancy'),
(7, '2020-12-01 10:28:00', '2020-12-01 13:02:00', 'accidents de la circulation', 'Nancy'),
(8, '2020-12-01 15:53:00', '2020-12-01 16:40:00', 'SUAP', 'Vandoeuvre'),
(9, '2020-12-01 20:08:00', '2020-12-02 03:30:00', 'risques technologiques', 'Laxou'),
(10, '2020-12-02 07:42:00', '2020-12-02 09:16:00', 'incendies', 'Vandoeuvre'),
(11, '2020-12-02 10:32:00', '2020-12-02 12:57:00', 'SUAP', 'Nancy'),
(12, '2020-12-02 14:16:00', '2020-12-02 15:28:00', 'SUAP', 'Nancy'),
(13, '2020-12-02 16:53:00', '2020-12-02 18:23:00', 'opérations diverses', 'Vandoeuvre'),
(14, '2020-12-02 19:34:00', '2020-12-02 21:08:00', 'incendies', 'Nancy');

-- --------------------------------------------------------

--
-- Structure de la table `Participe`
--

CREATE TABLE `Participe` (
  `idEq` int NOT NULL,
  `idInt` int NOT NULL,
  `DHdebPart` datetime DEFAULT NULL,
  `DHfinPart` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `Participe`
--

INSERT INTO `Participe` (`idEq`, `idInt`, `DHdebPart`, `DHfinPart`) VALUES
(1, 1, '2020-11-29 15:53:00', '2020-11-29 19:07:00'),
(1, 2, '2020-11-29 21:12:00', '2020-11-29 23:35:00'),
(2, 3, '2020-11-30 01:44:00', '2020-11-30 06:25:00'),
(3, 3, '2020-11-30 06:30:00', '2020-11-30 08:06:00'),
(3, 4, '2020-11-30 10:12:00', '2020-11-30 11:57:00'),
(4, 5, '2020-11-30 19:37:00', '2020-12-01 02:43:00'),
(5, 5, '2020-11-30 22:11:00', '2020-12-01 02:43:00'),
(5, 6, '2020-12-01 04:03:00', '2020-12-01 06:15:00'),
(6, 7, '2020-12-01 10:28:00', '2020-12-01 13:02:00'),
(7, 8, '2020-12-01 15:53:00', '2020-12-01 16:40:00'),
(7, 9, '2020-12-01 20:08:00', '2020-12-02 01:27:00'),
(8, 9, '2020-12-02 01:20:00', '2020-12-02 03:30:00'),
(9, 10, '2020-12-02 07:42:00', '2020-12-02 09:16:00'),
(9, 11, '2020-12-02 10:32:00', '2020-12-02 12:57:00'),
(10, 12, '2020-12-02 14:16:00', '2020-12-02 15:28:00'),
(10, 13, '2020-12-02 16:53:00', '2020-12-02 18:23:00'),
(10, 14, '2020-12-02 19:34:00', '2020-12-02 21:08:00');

-- --------------------------------------------------------

--
-- Structure de la table `Personnel`
--

CREATE TABLE `Personnel` (
  `Matricule` varchar(10) NOT NULL,
  `Nom` varchar(30) NOT NULL,
  `Prénom` varchar(30) NOT NULL,
  `Sexe` varchar(1) DEFAULT NULL,
  `Date_naissance` date DEFAULT NULL,
  `AdrVille` varchar(30) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `Personnel`
--

INSERT INTO `Personnel` (`Matricule`, `Nom`, `Prénom`, `Sexe`, `Date_naissance`, `AdrVille`) VALUES
('CH001', 'Carreau', 'Hélène', 'F', '1986-11-11', 'Laxou'),
('JB001', 'Joineau', 'Béatrice', 'F', '1980-01-18', 'Laxou'),
('JC001', 'Joineau', 'Charly', 'H', '1977-05-06', 'Nancy'),
('JS001', 'Joineau', 'Sam', 'H', '1983-05-27', 'Nancy'),
('MJ001', 'Maurice', 'Julie', 'F', '1987-01-05', 'Metz'),
('OB001', 'Ocean', 'Ben', 'H', '1993-07-14', 'Toul'),
('PD001', 'Prime', 'Denise', 'F', '1974-03-02', 'Nancy'),
('PE001', 'Portillon', 'Elvis', 'H', '1997-08-14', 'Metz'),
('SE001', 'Steele', 'Ernest', 'H', '1962-02-11', 'Toul'),
('TG001', 'Train', 'Gaston', 'H', '1960-12-20', 'Nancy'),
('TT001', 'Thomas', 'Tom', 'H', '1979-07-26', 'Nancy'),
('VT001', 'Volant', 'Tristan', 'H', '1967-10-23', 'Metz');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `Appartient`
--
ALTER TABLE `Appartient`
  ADD PRIMARY KEY (`Matricule`,`idEq`),
  ADD KEY `Constraint_Appartient_idEq` (`idEq`);

--
-- Index pour la table `Equipe`
--
ALTER TABLE `Equipe`
  ADD PRIMARY KEY (`idEq`);

--
-- Index pour la table `Intervention`
--
ALTER TABLE `Intervention`
  ADD PRIMARY KEY (`idInt`);

--
-- Index pour la table `Participe`
--
ALTER TABLE `Participe`
  ADD PRIMARY KEY (`idEq`,`idInt`),
  ADD KEY `Constraint_Participe_idInt` (`idInt`);

--
-- Index pour la table `Personnel`
--
ALTER TABLE `Personnel`
  ADD PRIMARY KEY (`Matricule`);

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `Appartient`
--
ALTER TABLE `Appartient`
  ADD CONSTRAINT `Constraint_Appartient_idEq` FOREIGN KEY (`idEq`) REFERENCES `Equipe` (`idEq`),
  ADD CONSTRAINT `Constraint_Appartient_Matricule` FOREIGN KEY (`Matricule`) REFERENCES `Personnel` (`Matricule`);

--
-- Contraintes pour la table `Participe`
--
ALTER TABLE `Participe`
  ADD CONSTRAINT `Constraint_Participe_idEq` FOREIGN KEY (`idEq`) REFERENCES `Equipe` (`idEq`),
  ADD CONSTRAINT `Constraint_Participe_idInt` FOREIGN KEY (`idInt`) REFERENCES `Intervention` (`idInt`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
