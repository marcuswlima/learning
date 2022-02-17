
drop DATABASE menagerie;

CREATE DATABASE menagerie;

use menagerie;

CREATE TABLE pet 
(name VARCHAR(20)
, owner VARCHAR(20)
, species VARCHAR(20)
, sex CHAR(1)
, birth DATE
, death DATE
);


INSERT INTO pet values('Fluffy','Harold','cat','f','1993-02-04',null);
INSERT INTO pet values('Claws','Gwen','cat','m','1994-03-17',null);
INSERT INTO pet values('Buffy','Harold','dog','f','1989-05-13',null);
INSERT INTO pet values('Fang','Benny','dog','m','1990-08-27',null);		
INSERT INTO pet values('Bowser','Diane','dog','m','1979-08-31','1995-07-29');	
INSERT INTO pet values('Chirpy','Gwen','bird','f','1998-09-11',null);	
INSERT INTO pet values('Whistler','Gwen','bird',null,'1997-12-09',null);	
INSERT INTO pet values('Slim','Benny','snake','m','1996-04-29',null);	

CREATE TABLE event (
name VARCHAR(20),
date DATE,
type VARCHAR(15), 
remark VARCHAR(255)
);

INSERT INTO event values('Fluffy','1995-05-15','litter','4 kittens, 3 female, 1 male');
INSERT INTO event values('Buffy','1993-06-23','litter','5 puppies, 2 female, 3 male');
INSERT INTO event values('Buffy','1994-06-19','litter','3 puppies, 3 female');
INSERT INTO event values('Chirpy','1999-03-21','vet','needed beak straightened');
INSERT INTO event values('Slim','1997-08-03','vet','broken rib');
INSERT INTO event values('Bowser','1991-10-12','kennel',null);	
INSERT INTO event values('Fang','1991-10-12','kennel',null);		
INSERT INTO event values('Fang','1998-08-28','birthday','Gave him a new chew toy');
INSERT INTO event values('Claws','1998-03-17','birthday','Gave him a new flea collar');
INSERT INTO event values('Whistler','1998-12-09','birthday','First birthday');

CREATE TABLE shop (
    article INT UNSIGNED  DEFAULT '0000' NOT NULL,
    dealer  CHAR(20)      DEFAULT ''     NOT NULL,
    price   DECIMAL(16,2) DEFAULT '0.00' NOT NULL,
    PRIMARY KEY(article, dealer));
INSERT INTO shop VALUES
    (1,'A',3.45),(1,'B',3.99),(2,'A',10.99),(3,'B',1.45),
    (3,'C',1.69),(3,'D',1.25),(4,'D',19.95);


drop user menagerie@'localhost';
CREATE USER menagerie@'localhost' IDENTIFIED BY 'M&nager1e' ;
GRANT all ON menagerie.* TO 'menagerie'@'localhost' WITH GRANT OPTION;
FLUSH PRIVILEGES;

