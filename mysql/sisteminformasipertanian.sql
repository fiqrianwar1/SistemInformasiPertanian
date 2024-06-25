-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Waktu pembuatan: 25 Jun 2024 pada 17.21
-- Versi server: 10.4.32-MariaDB
-- Versi PHP: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `sisteminformasipertanian`
--

-- --------------------------------------------------------

--
-- Struktur dari tabel `barang`
--

CREATE TABLE `barang` (
  `kode_barang` varchar(11) NOT NULL,
  `nama_barang` varchar(35) NOT NULL,
  `satuan` varchar(25) NOT NULL,
  `harga_beli` varchar(50) NOT NULL,
  `harga_jual` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data untuk tabel `barang`
--

INSERT INTO `barang` (`kode_barang`, `nama_barang`, `satuan`, `harga_beli`, `harga_jual`) VALUES
('a12', 'obat tumbuhan', 'III', '2500021112', '350001212'),
('d121', 'obat padi', 'I', '400000', '500000'),
('F13', 'bibit padi', 'IV', '20000', '30000');

-- --------------------------------------------------------

--
-- Struktur dari tabel `pelanggan`
--

CREATE TABLE `pelanggan` (
  `kode_pelanggan` varchar(11) NOT NULL,
  `nama_pelanggan` varchar(35) NOT NULL,
  `alamat_pelanggan` varchar(50) NOT NULL,
  `telp_pelanggan` varchar(20) NOT NULL,
  `fax_pelanggan` varchar(25) NOT NULL,
  `email_palanggan` varchar(50) NOT NULL,
  `tgl` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data untuk tabel `pelanggan`
--

INSERT INTO `pelanggan` (`kode_pelanggan`, `nama_pelanggan`, `alamat_pelanggan`, `telp_pelanggan`, `fax_pelanggan`, `email_palanggan`, `tgl`) VALUES
('a11', 'dani', 'BJM', '08192111', '112', 'dani12@gmail.com', '2023-01-01'),
('f12', 'wong', 'BJB', '0812121', '1211dd', 'wong@gmail.com', '2023-01-01');

-- --------------------------------------------------------

--
-- Struktur dari tabel `pembelian`
--

CREATE TABLE `pembelian` (
  `kode_barang` varchar(11) NOT NULL,
  `kode_supplier` varchar(11) NOT NULL,
  `no_faktur` varchar(25) NOT NULL,
  `tgl_faktur` date NOT NULL,
  `harga_jual` varchar(50) NOT NULL,
  `harga_beli` varchar(50) NOT NULL,
  `banyak_keluar` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data untuk tabel `pembelian`
--

INSERT INTO `pembelian` (`kode_barang`, `kode_supplier`, `no_faktur`, `tgl_faktur`, `harga_jual`, `harga_beli`, `banyak_keluar`) VALUES
('1', '2', '2', '2000-01-01', '2', '2', '2'),
('a335', 'g12', '41', '2000-01-01', '50000', '60000', '2');

-- --------------------------------------------------------

--
-- Struktur dari tabel `penjualan`
--

CREATE TABLE `penjualan` (
  `kode_pelanggan` varchar(11) NOT NULL,
  `no_faktur` varchar(35) NOT NULL,
  `tgl_faktor` date NOT NULL,
  `harga_beli` varchar(50) NOT NULL,
  `harga_jual` varchar(50) NOT NULL,
  `banyak_keluar` varchar(20) NOT NULL,
  `kode_barang` varchar(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data untuk tabel `penjualan`
--

INSERT INTO `penjualan` (`kode_pelanggan`, `no_faktur`, `tgl_faktor`, `harga_beli`, `harga_jual`, `banyak_keluar`, `kode_barang`) VALUES
('11', 'e21', '2020-01-01', '12312', '142141', '1', '211'),
('21', '121', '2000-01-01', '12112', '121', '121', '21'),
('a121', '1212', '2000-01-01', '421412', '1241212', '3', 'f12'),
('a1222', '12312', '2024-01-01', '31231', '411214', '1', '2');

-- --------------------------------------------------------

--
-- Struktur dari tabel `suppier`
--

CREATE TABLE `suppier` (
  `nama_supplier` varchar(25) NOT NULL,
  `kode_supplier` varchar(25) NOT NULL,
  `alamat_supplier` varchar(50) NOT NULL,
  `telp_supplier` varchar(20) NOT NULL,
  `fax_supplier` varchar(50) NOT NULL,
  `email_supplier` varchar(25) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data untuk tabel `suppier`
--

INSERT INTO `suppier` (`nama_supplier`, `kode_supplier`, `alamat_supplier`, `telp_supplier`, `fax_supplier`, `email_supplier`) VALUES
('roni', 'a123', 'bjm', '081931', '112d', 'roni12@gmail.com'),
('dono', 'f34', 'BJM', '0891212', '121', 'dono@gmail.com');

--
-- Indexes for dumped tables
--

--
-- Indeks untuk tabel `barang`
--
ALTER TABLE `barang`
  ADD PRIMARY KEY (`kode_barang`);

--
-- Indeks untuk tabel `pelanggan`
--
ALTER TABLE `pelanggan`
  ADD PRIMARY KEY (`kode_pelanggan`);

--
-- Indeks untuk tabel `pembelian`
--
ALTER TABLE `pembelian`
  ADD PRIMARY KEY (`no_faktur`);

--
-- Indeks untuk tabel `penjualan`
--
ALTER TABLE `penjualan`
  ADD PRIMARY KEY (`kode_pelanggan`);

--
-- Indeks untuk tabel `suppier`
--
ALTER TABLE `suppier`
  ADD PRIMARY KEY (`kode_supplier`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
