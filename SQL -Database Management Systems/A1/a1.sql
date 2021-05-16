rem dropping table
rem ***************************************************

drop table sungby;
drop table artist;
drop table song;
drop table album;
drop table studio;
drop table musician;

rem ***************************************************
rem creating tables

create table musician
(
	musician_ID number(5) constraint mid_pr primary key,
	musician_name varchar2(15) constraint mname_null not null,
	birthplace varchar2(20)
);

create table studio
(
	studio__name varchar2(15) constraint std_name_pr primary key,
	studio_address varchar2(20),
	phone number(10) 
);

create table album
(
	album_name varchar2(15) constraint alname_null not null,
	album_id number(10) constraint alid_pr primary key,
	year_of_release number(4) constraint addrelcheck check(year_of_release > 1945),
	no_of_tracks number(3) constraint ntrack_null not null,
	studio_name varchar2(20) constraint st_name_fk references studio(studio__name),
	album_genre varchar2(10) constraint a_check check(album_genre in ('CAR','DIV','MOV','POP')),
	musician__id number(5) constraint mid_fk references musician(musician_ID)
);

create table song
(
	album__id number(5) constraint aid_fk references album(album_id),
	track_no number(3),
	song_name varchar2(10) constraint sname_null not null,
	song_length number(4,2) constraint addsonglength_check check(song_length > 7),
	song_genre varchar2(20) constraint addsong_check check(song_genre in ('PHI','REL','LOV','DEV','PAT')),
	constraint al_track_pr primary key(album__id,track_no)
);

create table artist
(
	artist_id number(5) constraint arid_pr primary key,
	artist_name varchar2(20) constraint arname_un unique constraint arname_null not null
);

create table sungby
(
	album__ID number(5),
	artist__id number(5) constraint arid_fk references artist(artist_id),
	track__no number(3),
	recording_date date,
	constraint alb_trackno_pk foreign key(album__ID,track__no) references song(album__id,track_no),
	constraint sungby_pr primary key(album__ID,artist__id,track__no)
);


rem ************************************************************
rem inserting values into tables


insert into musician values
(
	10000,
	'BTS',
	'south korea'
);

insert into musician values
(
	10001,
	'Marshmellow',
	null
);

insert into musician values
(
	10002,
	'Alan Walker',
	null
);

insert into studio values
(
	'New Republic',
	'USA',
	null
);

insert into studio values
(
	'Vevo',
	'USA',
	9876543212
);

insert into album values
(
	'Love yourself',
	12,
	2019,
	8,
	'Vevo',
	'POP',
	10001
);


insert into album values
(
	'Thank You next',
	13,
	2018,
	8,
	'New Republic',
	'POP',
	10002
);

insert into song values
(
	12,
	7,
	'7 rings',
	8,
	'LOV'
);

insert into song values
(
	13,
	8,
	'Gucci gang',
	8,
	'REL'
);

insert into artist values
(
	101,
	'The weeknd'
);

insert into artist values
(
	102,
	'The chainsmokers'
);

insert into artist values
(
	104,
	'Twentyone pilots'
);

insert into sungby values
(
	12,
	102,
	7,
	'18-feb-2019'
);

insert into sungby values
(
	13,
	101,
	8,
	'14-feb-2019'
);
	
		
	
	
select * from musician;

select * from studio;

select * from album;

select * from song;

select * from artist;

select * from sungby;
	
	